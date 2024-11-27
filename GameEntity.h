#include <SFML/Graphics.hpp>
#ifndef GAMEENTITY_H
#define GAMEENTITY_H
using namespace sf;

class GameEntity : public Drawable {
public:
    virtual ~GameEntity() {} // Destructor virtual
    virtual Vector2f GetPosition() const = 0; // Método puro virtual para obtener la posición
    virtual void Update() = 0; // Método puro virtual para actualizar la entidad
};

#endif
