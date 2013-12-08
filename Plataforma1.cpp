#include "Plataforma1.h"

Plataforma1::Plataforma1()
{
    this->x=0;
    this->y=485;
    sprites.push_back(IMG_Load("Assests/plataforma1.png"));   //ctor
}

Plataforma1::~Plataforma1()
{
    //dtor
}
void Plataforma1::reset(){
x=0;
y=485;
}

