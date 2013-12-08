#include "Personaje.h"

Personaje::Personaje()
{
    this->x=0;
    this->y=435;
    this->saltar=false;
    tiempo=0;
    cuadro_actual=0;
    sprites.push_back(IMG_Load("Assests/personaje_principal/1.png"));
    sprites.push_back(IMG_Load("Assests/personaje_principal/2.png"));
    sprites.push_back(IMG_Load("Assests/personaje_principal/3.png"));
    sprites.push_back(IMG_Load("Assests/personaje_principal/4.png"));
    sprites.push_back(IMG_Load("Assests/personaje_principal/5.png"));
    sprites.push_back(IMG_Load("Assests/personaje_principal/6.png"));
}

Personaje::~Personaje()
{
    //dtor
}
void Personaje::Dibujar(SDL_Surface*screen,int cuadro_actual){
 //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = this->x;
    offset.y = this->y;

    //Blit
    SDL_BlitSurface( this->sprites[cuadro_actual], NULL, screen, &offset );
}
