#ifndef AGUA_H
#define AGUA_H
#include "Enemigo.h"

class Agua:public Enemigo
{
    public:
        Agua();
        bool para_arriba;
         void logica();
         int atacar(Personaje*personaje);
         void reset();
        virtual ~Agua();
    protected:
    private:
};

#endif // AGUA_H
