#include "Plataforma6.h"

Plataforma6::Plataforma6()
{
    this->x=900;
    this->y=350;
    this->moviendose_para_arriba=true;
     sprites.push_back(IMG_Load("Assests/plataforma_multiple.png"));//ctor
}

Plataforma6::~Plataforma6()
{
    //dtor
}
void Plataforma6::logica(Personaje*personaje){
if (moviendose_para_arriba==true){
    y--;
    x--;
}else{
y++;
x++;
}
  if (y==300)
    moviendose_para_arriba=true;
  if (y==200)
    moviendose_para_arriba=false;

if (personaje->x>=this->x-10&&personaje->x<=this->x+90&&personaje->y+50>=y-2&&personaje->y+50<y){
  if (moviendose_para_arriba==false){
   personaje->y--;
   personaje->y++;
   personaje->x++;
  }
else if (moviendose_para_arriba==true){
    personaje->y--;
    personaje->y--;
    personaje->x--;
}
}else if (personaje->x>=x&&personaje->x<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&
    personaje->saltar==true){
    personaje->saltar=false;
    personaje->y--;
    }
}
void Plataforma6::reset(){
x=900;
y=350;
 this->moviendose_para_arriba=true;
}

