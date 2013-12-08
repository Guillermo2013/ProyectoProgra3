#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
class Enemigo
{
    public:
        int cuadro_actual;
        int tiempo;
        std::vector<SDL_Surface*>sprites;
        int x,y;
        virtual void logica();
        virtual void Dibujar(SDL_Surface*screen,int cuadro_actual);
        virtual void reset();
        virtual int atacar(Personaje*personaje);
        virtual int recibir_ataque(Personaje*personaje);
        Enemigo();
        virtual ~Enemigo();
    protected:
    private:
};

#endif // ENEMIGO_H
