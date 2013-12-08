#include "Enemigo.h"

Enemigo::Enemigo()
{
    this->cuadro_actual=0;
    this->tiempo=0;
}

Enemigo::~Enemigo()
{
    //dtor
}
void Enemigo::Dibujar(SDL_Surface*screen,int cuadro_actual){
SDL_Rect offset;

    //Get offsets
    offset.x = this->x;
    offset.y = this->y;

    //Blit
    SDL_BlitSurface( this->sprites[cuadro_actual], NULL, screen, &offset );
}
void Enemigo::logica(){

}
void Enemigo::reset(){
}
int  Enemigo::atacar(Personaje*personaje){

return 0;
}
int Enemigo::recibir_ataque(Personaje*personaje){
    return 0;
}
