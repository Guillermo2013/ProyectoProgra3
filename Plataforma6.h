#ifndef PLATAFORMA6_H
#define PLATAFORMA6_H
#include "Plataforma.h"

class Plataforma6:public Plataforma
{
    public:
        Plataforma6();
         bool moviendose_para_arriba;
        void logica(Personaje*personaje);
        void reset();
        virtual ~Plataforma6();
    protected:
    private:
};

#endif // PLATAFORMA6_H
