#ifndef ENEMIGO2_H
#define ENEMIGO2_H
#include "Enemigo.h"


class Enemigo2:public Enemigo
{
    public:
        int cuadro_actual;
        Enemigo2();
        void reset();
        int atacar(Personaje*personaje);
        virtual ~Enemigo2();
    protected:
    private:
};

#endif // ENEMIGO2_H
