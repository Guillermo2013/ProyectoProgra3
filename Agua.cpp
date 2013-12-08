#include "Agua.h"

Agua::Agua()
{
    this->x=200;
    this->y=490;
    this->para_arriba=true;
    sprites.push_back(IMG_Load("Assests/agua.png"));
}

Agua::~Agua()
{
    //dtor
}
void Agua::logica(){
 if (para_arriba==true){
    y--;

}else{
y++;

}
  if (y==470)
    para_arriba=false;
  if (y==490)
    para_arriba=true;
}
void Agua::reset(){
this->x=200;
this->y=490;
  this->para_arriba=true;
}
int Agua::atacar(Personaje*personaje){
if (personaje->x+18>=x&&personaje->x+18<=x+549&&personaje->y+50>=y&&personaje->y+50<=y+10){
      personaje->x=0;
    personaje->y=435;
    personaje->cuadro_actual=0;
    reset();
    return -1;

}

  return 0;
}
