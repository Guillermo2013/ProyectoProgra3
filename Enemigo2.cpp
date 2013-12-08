#include "Enemigo2.h"

Enemigo2::Enemigo2()
{
   this->x=700;
   this->y=40;
   this->cuadro_actual=0;
sprites.push_back(IMG_Load("Assests/enemigo2/enemigo2_1.png"));
}

Enemigo2::~Enemigo2()
{
    //dtor
}
int  Enemigo2::atacar(Personaje*personaje){

if (personaje->x+30==x&&personaje->y+25>y&&personaje->y+25<y+60){
     personaje->x=0;
    personaje->y=435;
    personaje->cuadro_actual=0;
    reset();
    return -1;
}else if (personaje->x-10==x&&personaje->y+25>y&&personaje->y+25<y+60){
 personaje->x=0;
    personaje->y=435;
    personaje->cuadro_actual=0;
    reset();
return -1;
}else if (personaje->x+18>x&&personaje->x<x+60&&personaje->y==y+50){
 personaje->x=0;
    personaje->y=435;
    personaje->cuadro_actual=0;
    reset();
return -1;
}

return 0;
}
void Enemigo2::reset(){
  this->x=690;
   this->y=150;
   this->cuadro_actual=0;
}
