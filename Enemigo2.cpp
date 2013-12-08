#include "Enemigo2.h"

Enemigo2::Enemigo2()
{
   this->x=690;
   this->y=170;
   this->cuadro_actual=0;
sprites.push_back(IMG_Load("Assests/enemigo2/enemigo2_1.png"));
}

Enemigo2::~Enemigo2()
{
    //dtor
}
int  Enemigo2::atacar(Personaje*personaje){
if (personaje->x+33==x&&personaje->y+50>=y&&personaje->y+50<y+60){
     personaje->x=0;
    personaje->y=450;
    reset();
    return -1;
}else if (personaje->x==x+60&&personaje->y>=y+41&&personaje->y+50<y+60){
 personaje->x=0;
    personaje->y=450;
    reset();
return -1;
}else if(personaje->x>=x&&personaje->x<x+60&&personaje->y+5==y+55){
personaje->x=0;
    personaje->y=450;
    reset();
return -1;
}else if (personaje->x>x&&personaje->x<x+60&&personaje->y+50==y){
personaje->x=0;
    personaje->y=450;
    reset();
}
return 0;
}
void Enemigo2::reset(){
  this->x=690;
   this->y=150;
   this->cuadro_actual=0;
}
