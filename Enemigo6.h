#ifndef ENEMIGO6_H
#define ENEMIGO6_H
#include "Enemigo.h"

class Enemigo6:public Enemigo
{
    public:
        bool para_adelante;
        void logica();
        int recibir_ataque(Personaje*personaje);
        int atacar(Personaje*personaje);
        void reset();
        Enemigo6();
        virtual ~Enemigo6();
    protected:
    private:
};

#endif // ENEMIGO6_H
