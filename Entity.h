#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::Sprite sprite;
    sf::Vector2f direction;
    float speed;

public:
    // Constructor
    Entity(sf::Texture& texture, sf::Vector2f position, float speed)
        : speed(speed) {
        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
        sprite.setPosition(position);
        direction = sf::Vector2f(0.f, 0.f);
    }

    // Métodos virtuales para polimorfismo
    virtual void Update() = 0;  // Método virtual puro para actualizar la entidad
    virtual void Move() {  // Método para mover la entidad
        sprite.move(direction * speed);
    }

    // Método para dibujar la entidad en la ventana
    virtual void Draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    // Getter para obtener la posición de la entidad
    sf::Vector2f GetPosition() const {
        return sprite.getPosition();
    }

    // Destructor virtual
    virtual ~Entity() {}
};

#endif
