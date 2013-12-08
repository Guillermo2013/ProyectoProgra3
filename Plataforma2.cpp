#include "Plataforma2.h"

Plataforma2::Plataforma2()
{
   this->x=100;
    this->y=400;

    sprites.push_back(IMG_Load("Assests/plataforma_multiple.png"));
}

Plataforma2::~Plataforma2()
{
    //dtor
}
void Plataforma2::reset(){
x=100;
y=400;
}

void Plataforma2::logica(Personaje*personaje){
if (personaje->x>=x&&personaje->x<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&
    personaje->saltar==false){
        personaje->y--;

}else if (personaje->x>=x&&personaje->x<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&
    personaje->saltar==true){
    personaje->saltar=false;
    personaje->y--;
    }
}
