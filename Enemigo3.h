#ifndef ENEMIGO3_H
#define ENEMIGO3_H
#include "Enemigo.h"

class Enemigo3:public Enemigo
{
    public:
        bool para_adelante;
        void logica();
        int recibir_ataque(Personaje*personaje);
        int atacar(Personaje*personaje);
        void reset();
        Enemigo3();
        virtual ~Enemigo3();
    protected:
    private:
};

#endif // ENEMIGO3_H
