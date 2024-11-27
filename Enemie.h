#ifndef ENEMIE_H
#define ENEMIE_H
#include <utility> // Para std::pair
#include <bits/stdc++.h> 
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Enemie : public GameEntity {
    private:
        Sprite sprite;
        bool activado;
        float vel;
        int Hp;
        int dist;
        void Movement(Vector2f);
        void apuntarPlayer(Vector2f);
    public:
        Enemie(Vector2f, Texture&);
        void Update(Vector2f, int) ) override; // Sobrescribir el método Update
        Vector2f GetPosition() const override; // Sobrescribir el método GetPosition
        void TakeHp();
        int ConsultHp();
        virtual void draw(RenderTarget&, RenderStates) const override;
};
#endif 
