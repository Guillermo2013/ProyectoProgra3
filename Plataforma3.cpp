#include "Plataforma3.h"

Plataforma3::Plataforma3()
{
    this->x=200;
    this->y=330;
   *moviendose_para_delante=true;
     sprites.push_back(IMG_Load("Assests/plataforma_multiple.png"));
}

Plataforma3::~Plataforma3()
{
    //dtor
}
void Plataforma3::logica(Personaje*personaje){
if (*moviendose_para_delante==true)
   x++;
else if (*moviendose_para_delante==false)
    x--;
 if (x==300||x==100)
    *moviendose_para_delante=false;
 else if (x==150||x==0)
    *moviendose_para_delante=true;

 if (personaje->x>=x&&personaje->x<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&personaje->saltar==false){
  if (*moviendose_para_delante==false){
personaje->y--;
   personaje->x--;
  }
  else if (*moviendose_para_delante==true){
personaje->y--;
    personaje->x++;
}

}else if (personaje->x>=x&&personaje->x<=x+100&&personaje->y+50>=y-2&&personaje->y+50<y&&
    personaje->saltar==true){
    personaje->saltar=false;
    personaje->y--;

    }

}

void Plataforma3::reset(){
x=200;
y=300;
*moviendose_para_delante=true;
}
