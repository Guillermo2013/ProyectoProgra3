#ifndef ENEMIGO4_H
#define ENEMIGO4_H
#include "Enemigo.h"

class Enemigo4:public Enemigo
{
    public:
         bool para_adelante;
        void logica();
        int recibir_ataque(Personaje*personaje);
        int atacar(Personaje*personaje);
        void reset();
        Enemigo4();
        virtual ~Enemigo4();
    protected:
    private:
};

#endif // ENEMIGO4_H
