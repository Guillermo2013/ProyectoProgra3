#include "Plataforma7.h"

Plataforma7::Plataforma7()
{
    this->x=900;
    this->y=350;
    this->moviendose_para_arriba=true;
     sprites.push_back(IMG_Load("Assests/plataforma_multiple.png"));//ctor
}

Plataforma7::~Plataforma7()
{
    //dtor
}
void Plataforma7::logica(Personaje*personaje){
    if (moviendose_para_arriba==true){
    y--;

}else{
y++;

}
  if (y==100)
    moviendose_para_arriba=false;
  if (y==400)
    moviendose_para_arriba=true;
 if (personaje->x>=x&&personaje->x<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y){
  if (moviendose_para_arriba==false){
   personaje->y--;
   personaje->y++;
  }
  else if (moviendose_para_arriba==true){
    personaje->y--;
    personaje->y--;
}

}else if (personaje->x>=x&&personaje->x<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&
    personaje->saltar==true){
    personaje->saltar=false;
    personaje->y--;
    }

}
void Plataforma7::reset(){
x=900;
y=350;
}
