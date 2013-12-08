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
return 0;
}
int Enemigo3::recibir_ataque(Personaje*personaje){
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

if (x==0){
    para_adelante=true;
}else if (x==150){
para_adelante=false;
}

}
void Enemigo3::reset(){
this->x=150;
    this->y=425;
    this->tiempo=0;
    this->cuadro_actual=0;
    this->para_adelante=false
}
