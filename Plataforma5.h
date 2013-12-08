#ifndef PLATAFORMA5_H
#define PLATAFORMA5_H
#include "Plataforma.h"

class Plataforma5:public Plataforma
{
    public:
        Plataforma5();
        void logica(Personaje*personaje);
        virtual ~Plataforma5();
        void reset();
    protected:
    private:
};

#endif // PLATAFORMA5_H
