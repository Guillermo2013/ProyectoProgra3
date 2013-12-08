#ifndef PLATAFORMA7_H
#define PLATAFORMA7_H
#include "Plataforma.h"

class Plataforma7:public Plataforma
{
    public:
        Plataforma7();
        bool moviendose_para_arriba;
        void logica(Personaje*personaje);
        void reset();
        virtual ~Plataforma7();
    protected:
    private:
};

#endif // PLATAFORMA7_H
