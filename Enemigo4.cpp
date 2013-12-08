#include "Enemigo4.h"

Enemigo4::Enemigo4()
{
    this->x=940;
    this->y=450;
    this->tiempo=0;
    this->cuadro_actual=0;
    this->para_adelante=false;
    sprites.push_back(IMG_Load("Assests/emenigo4/enemigo4_1.png"));
    sprites.push_back(IMG_Load("Assests/emenigo4/enemigo4_2.png"));
    sprites.push_back(IMG_Load("Assests/emenigo4/enemigo4_3.png"));
    sprites.push_back(IMG_Load("Assests/emenigo4/enemigo4_4.png"));
}

Enemigo4::~Enemigo4()
{
    //dtor
}
int Enemigo4::atacar(Personaje*personaje){
if (personaje->x+30==x&&personaje->y+25>y&&personaje->y+25<y+32){
     personaje->x=0;
    personaje->y=435;
    personaje->cuadro_actual=0;
    reset();
    return -1;
}else if (personaje->x-10==x&&personaje->y+25>y&&personaje->y+25<y+32){
 personaje->x=0;
    personaje->y=435;
    personaje->cuadro_actual=0;
    reset();
return -1;
}else if (personaje->x+18>x&&personaje->x<x+60&&personaje->y==y+20){
 personaje->x=0;
    personaje->y=435;
    personaje->cuadro_actual=0;
    reset();
return -1;
}

return 0;
}
int Enemigo4::recibir_ataque(Personaje*personaje){
if (personaje->x+18>x&&personaje->x+18<x+60&&personaje->y+40==y){
  return 10;
}else
return 0;
}
void Enemigo4::logica(){
tiempo++;
if (para_adelante==false){
x--;
    cuadro_actual=0;
}else if (para_adelante==true){
cuadro_actual=2;
x++;
}
if (tiempo==10){
   cuadro_actual++;
    if (para_adelante==false){
        if (cuadro_actual==0)
            cuadro_actual=1;
        }else if (para_adelante==true){
       if (cuadro_actual==2)
            cuadro_actual=3;
       }
    tiempo=0;

}

if (x==550||x==750){
    para_adelante=true;
}else if (x==740||x==940){
para_adelante=false;
}

}
void Enemigo4::reset(){
   this->x=940;
    this->y=450;
    this->tiempo=0;
    this->cuadro_actual=0;
    this->para_adelante=false;
}
