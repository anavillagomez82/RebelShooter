#include <bits/stdc++.h> 
#include <SFML/Graphics.hpp>
#ifndef PLAYER_H
#define PLAYER_H
#include "GameEntity.h"

class Player : public GameEntity {
public:
    Player(Texture&);
    void Update(RenderWindow&, View&) override; // Sobrescribir el método Update
    Vector2f GetPosition() const override; // Sobrescribir el método GetPosition
    pair<bool, Vector2f> AnswerShoot(RenderWindow&); // Método específico de Player
    float GetRotation(); // Método específico de Player
    virtual void draw(RenderTarget&, RenderStates) const override;

private:
    Sprite sprite;
    float vel;
    int cadencia = 8;
    void Movement(View&);
    void apuntar(RenderWindow&);
};
#endif
