#include "Plataforma4.h"

Plataforma4::Plataforma4()
{
    this->x=400;
    this->y=200;
    this->moviendose_para_arriba=true;
     sprites.push_back(IMG_Load("Assests/plataforma_multiple.png"));//ctor
}

Plataforma4::~Plataforma4()
{
    //dtor
}
void Plataforma4::logica(Personaje*personaje){
if (moviendose_para_arriba==true&&y<=400)
   y++;
 if (y==400)
    moviendose_para_arriba=false;
 if (moviendose_para_arriba==false&&y>=200)
    y--;
 if (y==200)
    moviendose_para_arriba=true;

  if (personaje->x+18>=x&&personaje->x+18<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&personaje->saltar==false){
  if (moviendose_para_arriba==false){
   personaje->y--;
   personaje->y--;

  }
  else if (moviendose_para_arriba==true){
    personaje->y++;
    personaje->y--;
}

}else if (personaje->x+18>=x&&personaje->x+18<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&
    personaje->saltar==true){
    personaje->saltar=false;
    personaje->y--;

    }


}
void Plataforma4::reset(){
x=400;
y=200;
this->moviendose_para_arriba=true;
}
