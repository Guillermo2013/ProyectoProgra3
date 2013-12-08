#ifndef ENEMIGO5_H
#define ENEMIGO5_H
#include "Enemigo.h"

class Enemigo5:public Enemigo
{
    public:
        bool para_adelante;
        void logica();
        int recibir_ataque(Personaje*personaje);
        int atacar(Personaje*personaje);
        void reset();
        Enemigo5();
        virtual ~Enemigo5();
    protected:
    private:
};

#endif // ENEMIGO5_H
