#include "Plataforma5.h"

Plataforma5::Plataforma5()
{
    this->x=500;
    this->y=200;

     sprites.push_back(IMG_Load("Assests/plataforma5.png"));//ctor
}

Plataforma5::~Plataforma5()
{
    //dtor
}
void Plataforma5::reset(){
x=500;
y=200;
}
void Plataforma5::logica(Personaje*personaje){


if (personaje->x+18>=x&&personaje->x+18<=x+250&&personaje->y+50>=y-2&&personaje->y+50<y&&personaje->saltar==false){
        personaje->y--;

}else if (personaje->x+18>=x&&personaje->x+18<=x+250&&personaje->y+50>=y-2&&personaje->y+50<y&&
    personaje->saltar==true){
    personaje->saltar=false;
    personaje->y--;
    }
}
