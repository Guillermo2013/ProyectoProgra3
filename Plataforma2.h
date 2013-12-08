#ifndef PLATAFORMA2_H
#define PLATAFORMA2_H
#include "Plataforma.h"

class Plataforma2:public Plataforma
{
    public:
        Plataforma2();
    void reset();
    void logica(Personaje*personaje);
        virtual ~Plataforma2();
    protected:
    private:
};

#endif // PLATAFORMA2_H
