#ifndef PLATAFORMA4_H
#define PLATAFORMA4_H
#include "Plataforma.h"

class Plataforma4:public Plataforma
{
    public:
        Plataforma4();
         bool moviendose_para_arriba;
        void logica(Personaje*personaje);
        void reset();
        virtual ~Plataforma4();
    protected:
    private:
};

#endif // PLATAFORMA4_H
