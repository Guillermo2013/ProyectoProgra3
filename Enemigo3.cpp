#include "Enemigo3.h"

Enemigo3::Enemigo3()
{
    this->x=150;
    this->y=425;
    this->tiempo=0;
    this->cuadro_actual=0;
    this->para_adelante=false;
    sprites.push_back(IMG_Load("Assests/enemigo3/emenigo3_1.png"));
    sprites.push_back(IMG_Load("Assests/enemigo3/emenigo3_2.png"));
    sprites.push_back(IMG_Load("Assests/enemigo3/emenigo3_3.png"));
    sprites.push_back(IMG_Load("Assests/enemigo3/emenigo3_4.png"));
}

Enemigo3::~Enemigo3()
{
    //dtor
}
int Enemigo3::atacar(Personaje*personaje){
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
}else if (personaje->x+18>x&&personaje->x<x+40&&personaje->y==y+50){
 personaje->x=0;
    personaje->y=435;

    reset();
return -1;
}

return 0;
}
int Enemigo3::recibir_ataque(Personaje*personaje){
if (personaje->x+18>x&&personaje->x+18<x+40&&personaje->y+40==y){
  return 10;
}else
return 0;
}
void Enemigo3::logica(){
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

if (x==0||x==-200){
    para_adelante=true;
}else if (x==150||x==-50){
para_adelante=false;
}

}
void Enemigo3::reset(){
this->x=150;
    this->y=425;
    this->tiempo=0;
    this->cuadro_actual=0;
    this->para_adelante=false;
}
