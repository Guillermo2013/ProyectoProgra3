#ifndef ENEMIGO1_H
#define ENEMIGO1_H
#include "Enemigo.h"

class Enemigo1:public Enemigo
{
    public:

        bool para_abajo;
        void logica();
        void reset();
        int atacar(Personaje*personaje);
        int recibir_ataque(Personaje*personaje);
        Enemigo1();
        virtual ~Enemigo1();
    protected:
    private:
};

#endif // ENEMIGO1_H
