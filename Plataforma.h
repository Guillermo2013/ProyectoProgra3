#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "Personaje.h"

class Plataforma
{
    public:
        Plataforma();
        int x,y;
        std::vector<SDL_Surface*>sprites;
        virtual void Dibujar(SDL_Surface*screen);
        virtual void logica(Personaje*personaje);
        virtual void reset();
        virtual ~Plataforma();
    protected:
    private:
};

#endif // PLATAFORMA_H
