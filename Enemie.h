#include <bits/stdc++.h> 
#include <SFML/Graphics.hpp>
#ifndef ENEMIE_H
#define ENEMIE_H
#include "Entity.h"
using namespace std;
using namespace sf;

class Enemy : public Entity {
private:
    bool isAggressive;

public:
    // Constructor del enemigo
    Enemy(sf::Texture& texture, sf::Vector2f position)
        : Entity(texture, position, 2.f), isAggressive(false) {}

    // Implementación de la función Update específica para el enemigo
    void Update() override {
        if (isAggressive) {
            chasePlayer();
        } else {
            randomMovement();
        }

        Move();
    }

    // Método para hacer que el enemigo persiga al jugador
    void chasePlayer() {
        sf::Vector2f playerPosition(500.f, 300.f);  // Ejemplo de posición del jugador (debes usar la posición real)
        direction = playerPosition - sprite.getPosition();
        direction /= std::sqrt(direction.x * direction.x + direction.y * direction.y);  // Normalizar la dirección
    }

    // Movimiento aleatorio del enemigo
    void randomMovement() {
        direction = sf::Vector2f(rand() % 3 - 1, rand() % 3 - 1);  // Movimiento aleatorio [-1, 1]
    }

    // Cambiar el estado de agresividad del enemigo
    void setAggression(bool aggressive) {
        isAggressive = aggressive;
    }
};

#endif
