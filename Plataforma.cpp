#include "Plataforma.h"

Plataforma::Plataforma()
{

}

Plataforma::~Plataforma()
{
    //dtor
}
void Plataforma::Dibujar(SDL_Surface*screen){
 //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = this->x;
    offset.y = this->y;

    //Blit
    SDL_BlitSurface( this->sprites[0], NULL, screen, &offset );
}
void Plataforma::logica(Personaje*personaje){


}
void Plataforma::reset(){
}

