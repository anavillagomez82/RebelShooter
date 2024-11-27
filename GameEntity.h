#include <SFML/Graphics.hpp>
#ifndef GAMEENTITY_H
#define GAMEENTITY_H
#include <utility> // Para std::pair
using namespace sf;

class GameEntity : public Drawable {
public:
    virtual ~GameEntity() = default; // Destructor virtual
    virtual Vector2f GetPosition() const = 0; // Método puro virtual para obtener la posición
    virtual void Update() = 0; // Método puro virtual para actualizar la entidad
    virtual void draw(RenderTarget& target, RenderStates states) const override = 0; // Método virtual puro
};

#endif
