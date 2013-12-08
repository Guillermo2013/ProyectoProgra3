#include "Enemigo1.h"

Enemigo1::Enemigo1()
{
this->x=200;
this->y=200;
this->para_abajo=true;
sprites.push_back(IMG_Load("Assests/enemigo1/enemigo1_1.png"));
sprites.push_back(IMG_Load("Assests/enemigo1/enemigo1_2.png"));
sprites.push_back(IMG_Load("Assests/enemigo1/enemigo1_3.png"));
sprites.push_back(IMG_Load("Assests/enemigo1/enemigo1_4.png"));



}

Enemigo1::~Enemigo1()
{
    //dtor
}
int Enemigo1::atacar(Personaje*personaje){

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
void Enemigo1::reset(){
this->x=200;
this->y=200;
this->para_abajo=true;

}
void Enemigo1::logica(){
 tiempo++;
    if (tiempo==10){
        cuadro_actual++;
        if (cuadro_actual>=4){
            cuadro_actual=0;
        }
        tiempo=0;
    }
    if (para_abajo==true){
        y++;
    }
    else{
        y--;
    }
    if (y==200){
        para_abajo=true;
    }else if(y==400)
    para_abajo=false;
}
int Enemigo1::recibir_ataque(Personaje*personaje){
if (personaje->x+18>x&&personaje->x+18<x+60&&personaje->y+40==y){
  return 10;
}else
return 0;
}
