#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "SDL.h"
#include "SDL_image.h"
#include <vector>

class Personaje
{
    public:
        int x,y;
        bool saltar;
        int tiempo;
        int cuadro_actual;
        std::vector<SDL_Surface*>sprites;
        virtual void Dibujar(SDL_Surface*screen,int cuadro_actual);
        Personaje();
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
