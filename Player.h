#include <bits/stdc++.h> 
#include <SFML/Graphics.hpp>
#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
using namespace std;
using namespace sf;


class Player : public Entity {
private:
    bool isShooting;

public:
    // Constructor del jugador
    Player(sf::Texture& texture, sf::Vector2f position)
        : Entity(texture, position, 5.f), isShooting(false) {}

    // Implementación de la función Update específica para el jugador
    void Update() override {
        // Lógica de movimiento del jugador
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            direction = sf::Vector2f(0.f, -1.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            direction = sf::Vector2f(0.f, 1.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            direction = sf::Vector2f(-1.f, 0.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            direction = sf::Vector2f(1.f, 0.f);
        } else {
            direction = sf::Vector2f(0.f, 0.f);
        }

        Move();

        // Lógica de disparo
        if (isShooting) {
            shoot();
        }
    }

    // Función para simular disparos
    void shoot() {
        std::cout << "El jugador está disparando!" << std::endl;
    }

    // Método para activar o desactivar el disparo
    void setShooting(bool shooting) {
        isShooting = shooting;
    }

    // Obtener la posición del jugador
    sf::Vector2f GetPlayerPosition() const {
        return sprite.getPosition();
    }
};

#endif
