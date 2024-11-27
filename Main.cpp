#include <SFML/Graphics.hpp>
#include "Player.h"
#include "proyectil.h"
#include "Enemie.h"
#include "UISonidos.h"
#include "Menu.h"
#include "GameEntity.h" 
#include <memory> // Para std::unique_ptr
#include <vector>
#include <utility> // Para std::pair

using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1010, 650), "Rebel Point");
    window.setFramerateLimit(60);

    Menu menu;

    bool inMenu = true;
    bool live = true;

    // Crear un vector de punteros a GameEntity
    vector<unique_ptr<GameEntity>> entities;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();

            if (inMenu) {
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Up) {
                        menu.MoveUp();
                    }
                    if (event.key.code == Keyboard::Down) {
                        menu.MoveDown();
                    }
                    if (event.key.code == Keyboard::Enter) {
                        if (menu.isStartPressed()) {
                            inMenu = false; 
                        } else {
                            window.close();
                        }
                    }
                }
            }
        }

        window.clear();

        if (inMenu) {
            menu.draw(window);
        } else {
            View vista;
            vista.setSize(1010, 650);
            vista.setCenter(0, 0);

            Texture playerTexture;
            Texture enemieTexture;
            Texture proyectilTexture;
            Texture bloodTexture;
            Texture fondoTextura;

            if (!playerTexture.loadFromFile("player.png")) {
                cout << "Error al cargar la textura" << endl;
            }
            if (!enemieTexture.loadFromFile("enemie.png")) {
                cout << "Error al cargar la textura" << endl;
            }
            if (!proyectilTexture.loadFromFile("proyectil.png")) {
                cout << "Error al cargar la textura" << endl;
            }
            if (!bloodTexture.loadFromFile("blood.png")) {
                cout << "Error al cargar la textura" << endl;
            }
            if (!fondoTextura.loadFromFile("fondo.png")) {
                cout << "Error al cargar la textura" << endl;
            }

            Sprite fondo;
            fondo.setTexture(fondoTextura);
            fondo.setOrigin(fondoTextura.getSize().x / 2, fondoTextura.getSize().y / 2);
            fondo.setPosition(0, 0);

            UISonidos uisonidos;
            // Crear el jugador y añadirlo a entities
            entities.push_back(make_unique<Player>(playerTexture));
            vector<Proyectil> proyectilesPlayer;
            vector<pair<Sprite, float>> bloodEnemies;
            Vector2f proyectilPosition;
            bool live = true;
            int dist = 350;
            int score = 0;

            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) window.close();
                }

                if (live) {
                    // Aleatorio
                    srand(time(NULL));
                    while (entities.size() < 55) {
                        IntRect backgroundRect(entities[0]->GetPosition().x - 505, entities[0]->GetPosition().y - 325, 1000, 650);
                        int x = (rand() % 1450) - 725; // -725 a 724
                        int y = (rand() % 950) - 475;  // -475 a 474
                        if (!backgroundRect.contains(x, y)) 
                            entities.push_back(make_unique<Enemie>(Vector2f(x, y), enemieTexture));
                    }

                    // Actualizar el jugador
                    entities[0]->Update(window, vista);

                    // Actualizar enemigos
                    for (size_t i = 1; i < entities.size(); i++) {
                        entities[i]->Update(entities[0]->GetPosition(), dist);
                    }

                    Vector2f playerPos = entities[0]->GetPosition();
                    IntRect playerRect(playerPos.x - 10, playerPos.y - 10, 25, 25);
                    for (size_t i = 1; i < entities.size (); i++) {
                        if (playerRect.intersects(entities[i]->GetGlobalBounds())) {
                            live = false; // El jugador ha sido alcanzado
                        }
                    }

                    // Dibujar fondo y entidades
                    window.draw(fondo);
                    for (const auto& entity : entities) {
                        entity->draw(window);
                    }
                } else {
                   
                }

                window.display();
            }
        }
    }
    return 0;
}
