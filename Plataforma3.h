#ifndef PLATAFORMA3_H
#define PLATAFORMA3_H
#include "Plataforma.h"

class Plataforma3:public Plataforma
{
    public:
        Plataforma3();
        bool *moviendose_para_delante=new bool();
        void logica(Personaje*personaje);
        void reset();
        virtual ~Plataforma3();
    protected:
    private:
};

#endif // PLATAFORMA3_H
