#include "Enemigo6.h"

Enemigo6::Enemigo6(){

    this->x=850;
    this->y=0;
    this->tiempo=0;
    this->cuadro_actual=0;
    this->para_adelante=false;
    sprites.push_back(IMG_Load("Assests/enemigo6/enemigo6_1.png"));
    sprites.push_back(IMG_Load("Assests/enemigo6/enemigo6_2.png"));
    sprites.push_back(IMG_Load("Assests/enemigo6/enemigo6_3.png"));
    sprites.push_back(IMG_Load("Assests/enemigo6/enemigo6_4.png"));
}

Enemigo6::~Enemigo6()
{
    //dtor
}
int Enemigo6::atacar(Personaje*personaje){
if (personaje->x+30==x&&personaje->y+25>y&&personaje->y+25<y+60){
     personaje->x=0;
    personaje->y=435;

    reset();
    return -1;
}else if (personaje->x-10==x&&personaje->y+25>y&&personaje->y+25<y+60){
 personaje->x=0;
    personaje->y=435;

    reset();
return -1;
}else if (personaje->x+18>x&&personaje->x<x+60&&personaje->y==y+50){
 personaje->x=0;
    personaje->y=435;
    reset();
return -1;
}

return 0;
}
int Enemigo6::recibir_ataque(Personaje*personaje){
if (personaje->x+18>x&&personaje->x+18<x+60&&personaje->y+40==y){
  return 10;
}else
return 0;
}
void Enemigo6::logica(){
tiempo++;
if (para_adelante==true){
x++;
y--;
    cuadro_actual=0;
}else if (para_adelante==false){
cuadro_actual=2;
x--;
y++;
}
if (tiempo==10){
   cuadro_actual++;
    if (para_adelante==true){
        if (cuadro_actual==0)
            cuadro_actual=1;
        }else if (para_adelante==false){
       if (cuadro_actual==2)
            cuadro_actual=3;
       }
    tiempo=0;

}

if (y==250){
    para_adelante=true;
}else if (y==0){
para_adelante=false;
}

}
void Enemigo6::reset(){
 this->x=900;
    this->y=0;
    this->tiempo=0;
    this->cuadro_actual=0;
    this->para_adelante=true;
}
