#ifndef PLATAFORMA8_H
#define PLATAFORMA8_H
#include "Plataforma.h"
class Plataforma8:public Plataforma
{
    public:
        Plataforma8();
        void reset();
        void logica(Personaje*personaje);
        virtual ~Plataforma8();
    protected:
    private:
};

#endif // PLATAFORMA8_H
