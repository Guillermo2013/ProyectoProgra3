#include "Plataforma8.h"

Plataforma8::Plataforma8()
{
    this->x=900;
    this->y=49;
     sprites.push_back(IMG_Load("Assests/plataforma_multiple.png"));
}

Plataforma8::~Plataforma8()
{
    //dtor
}
void Plataforma8::reset(){
x=900;
y=49;
}
void Plataforma8::logica(Personaje*personaje){
if (personaje->x+18>=x&&personaje->x+18<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&personaje->saltar==false){
        personaje->y--;

}else if (personaje->x+18>=x&&personaje->x+18<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&
    personaje->saltar==true){
    personaje->saltar=false;
    personaje->y--;
    }
}
