#include "Enemie.h"

Enemie::Enemie(Vector2f pos, Texture &texture){
    sprite.setTexture(texture);
    sprite.setScale(0.35,0.35);
    sprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    sprite.setPosition(pos);
    vel = 1.8;
    Hp = 100;
    activado = false;
}

void Enemie::Update(Vector2f posPlayer,int dista){
    dist=dista;
    Movement(posPlayer);
    apuntarPlayer(posPlayer);
}

void Enemie::Movement(Vector2f posPlayer){
    Vector2f dir = Vector2f(posPlayer-sprite.getPosition());
    Vector2f dirNorm = Vector2f(dir.x/sqrt(pow(dir.x,2)+pow(dir.y,2)),dir.y/sqrt(pow(dir.x,2)+pow(dir.y,2)));
    if(abs(dir.x)+abs(dir.y)<=dist||activado) 
        sprite.move(dirNorm.x*vel,dirNorm.y*vel);
}

void Enemie::apuntarPlayer(Vector2f posPlayer){
    Vector2f dir = Vector2f(posPlayer-sprite.getPosition());
    if(abs(dir.x)+abs(dir.y)<=dist||activado) 
        sprite.setRotation(atan2(posPlayer.y-sprite.getPosition().y,posPlayer.x-sprite.getPosition().x)*180/3.14159265f);
}

void Enemie::TakeHp(){
    Hp -= 20;
    activado = true;
}

int Enemie::ConsultHp(){
    return Hp;
}
Vector2f Enemie::GetPosition(){
    return sprite.getPosition();
}

void Enemie::draw(RenderTarget &rt, RenderStates rs) const{
    rt.draw(sprite,rs);
}