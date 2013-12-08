/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Enemigo.h"
#include "Enemigo1.h"
#include "Enemigo2.h"
#include "Enemigo3.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Plataforma1.h"
#include "Plataforma2.h"
#include "Plataforma3.h"
#include "Plataforma4.h"
#include "Plataforma5.h"
#include "Plataforma6.h"
#include "Plataforma7.h"
#include "Plataforma8.h"
#include "Agua.h"
//Screen attributes
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 540;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *up = NULL;
SDL_Surface *down = NULL;
SDL_Surface *left = NULL;
SDL_Surface *right = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The font
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 0, 3, 4 };

SDL_Surface *load_image( std::string filename )
{
       return IMG_Load( filename.c_str() );
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Press an Arrow Key", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the background image
    background = load_image( "Assests/Menu_imagen_fondo.png" );

    //Open the font
    font = TTF_OpenFont( "lazy.ttf", 50 );

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( up );
    SDL_FreeSurface( down );
    SDL_FreeSurface( left );
    SDL_FreeSurface( right );

    //Close the font
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}
std::string toString(int number)
{
    if (number == 0)
        return "0";
    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=(number%10+48);
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}


int main( int argc, char* args[] )
{

    SDL_Surface* Menu=load_image("Assests/menu.png");
    SDL_Surface* cursor_menu=load_image("Assests/cursor_menu.png");
    SDL_Surface* high_score=load_image("Assests/score.png");
    SDL_Surface* cursor_nivel=load_image("Assests/cursor_nivel.png");
    SDL_Surface* instrucciones=load_image("Assests/instrucciones.png");
    SDL_Surface* fondo_juego=load_image("Assests/fondo_juego.png");
    SDL_Surface* nivel=load_image("Assests/nivel.png");
    SDL_Surface* door=load_image("Assests/door.png");
    SDL_Surface* corazon=load_image("Assests/corazon.png");
    SDL_Surface* ganador=load_image("Assests/ganador.png");
    SDL_Surface* perdio=load_image("Assests/perdedor.png");
    Personaje* personaje=new Personaje();

    std::vector<Plataforma*>plataformas;
    plataformas.push_back(new Plataforma1());
    plataformas.push_back(new Plataforma2());
    plataformas.push_back(new Plataforma3());
    plataformas.push_back(new Plataforma4());
    plataformas.push_back(new Plataforma5());
    plataformas.push_back(new Plataforma6());
    plataformas.push_back(new Plataforma7());
    plataformas.push_back(new Plataforma8());
   std::vector<Enemigo *>enemigos;
    enemigos.push_back(new Agua());
     enemigos.push_back(new Enemigo1());
     enemigos.push_back(new Enemigo2());
      enemigos.push_back(new Enemigo3());
   std::ofstream escritura_puntaje("puntaje.txt",std::ios::app);
   std::ifstream lectura_puntaje("puntaje.txt");
    int cursor_x=0;
    int score=0;
    int cursor_nivel_x=0;
    int puerta_x=940;
    int puerta_y=0;
    int puntuacion=0;
    int vida_easy=3;
    int vida_mediun=2;
    int vida_hard=1;
    bool menu_bool=true;
    bool ganar=false;
    bool perder=false;
    bool nivel_bool=true;
    bool jugar=false;
    int menu_x=0;
    bool movimiento_de_pantalla=false;
    int tiempo_de_espera_de_ganar=0;
    int saltar=0;
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    //Render the text
    up = TTF_RenderText_Solid( font, "Up", textColor );
    down = TTF_RenderText_Solid( font, "Down", textColor );
    left = TTF_RenderText_Solid( font, "Left", textColor );
    right = TTF_RenderText_Solid( font, "Right", textColor );

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
         SDL_Surface * puntuacion_texto = TTF_RenderText_Solid( font,toString(puntuacion).c_str(), textColor );

        //Apply the background
        if (menu_bool==true){
             if (cursor_x>3){
                cursor_x=0;
                }else if (cursor_x<=-1){
                cursor_x=3;
            }
            apply_surface( 0, 0, background, screen );
             apply_surface( 0, 0, Menu, screen );
             apply_surface(cursor_x*190+40,280,cursor_menu,screen);
        }


        if (cursor_x==0&&nivel_bool==true&&menu_bool==false){
            if (cursor_nivel_x>2){
                cursor_nivel_x=0;
            }else if (cursor_nivel_x<=-1){
                cursor_nivel_x=2;
            }
                apply_surface( 0, 0, background, screen );
                 apply_surface( 0, 0, nivel, screen );
                apply_surface(cursor_nivel_x*231+85,248,cursor_nivel,screen);
            }
        if (menu_bool==false&&nivel_bool==true&&cursor_x==1){
               apply_surface( 0, 0, background, screen );
                apply_surface( 0, 0, instrucciones, screen );



        }
        if (menu_bool==false&&nivel_bool==true&&cursor_x==2){
               apply_surface( 0, 0, background, screen );
                apply_surface( 0, 0, high_score, screen );

            int score=-999999;
             lectura_puntaje.seekg(0);
            while(!lectura_puntaje.eof())
                {
                    int puntos;
                    lectura_puntaje>>puntos;
                    if(score<puntos)
                    {
                        score=puntos;
                    }
                }

             SDL_Surface * score_texto = TTF_RenderText_Solid( font,toString(score).c_str(), textColor );
             apply_surface(350,250,score_texto,screen);

        }

        if (menu_bool==false&&nivel_bool==true&&cursor_x==3){
        exit(0);
        }

        if (jugar==true){

        menu_bool=false;
        nivel_bool=false;

        apply_surface( menu_x, 0,fondo_juego , screen );
         apply_surface( puerta_x, puerta_y,door, screen );



        for (int x=0;x<plataformas.size();x++){
           plataformas[x]->Dibujar(screen);
        }

        personaje->Dibujar(screen,personaje->cuadro_actual);

        for (int x=0;x<plataformas.size();x++){
           plataformas[x]->logica(personaje);
        }
         for (int x=0;x<enemigos.size();x++){
          enemigos[x]->Dibujar(screen,enemigos[x]->cuadro_actual);
        }

        for (int x=0;x<enemigos.size();x++){
           enemigos[x]->logica();
        }

      for(int i=0;i<enemigos.size();i++)
      if (enemigos[i]->atacar(personaje)==-1){
           if (cursor_nivel_x==0){
              vida_easy--;
              if (puntuacion>500)
              puntuacion-=500;
              else
                puntuacion=0;
           }else if (cursor_nivel_x==1){
          vida_mediun--;
          if (puntuacion>500)
              puntuacion-=500;
              else
                puntuacion=0;
           } else if (cursor_nivel_x==2){
           vida_hard--;
           if (puntuacion>500)
              puntuacion-=500;
              else
                puntuacion=0;
           }


        if (personaje->x==0&&movimiento_de_pantalla==true){
          movimiento_de_pantalla=false;
            personaje->x=0;
            menu_x+=200;
            puerta_x+=200;
            for(int i=0;i<plataformas.size();i++)
            plataformas[i]->reset();
            for(int i=0;i<enemigos.size();i++)
        enemigos[i]->reset();

        }else if (personaje->x>=500&&movimiento_de_pantalla==false){
          movimiento_de_pantalla=true;
            personaje->x-=200;
            menu_x-=200;
            puerta_x-=200;
            for(int i=0;i<plataformas.size();i++)
           plataformas[i]->x=plataformas[i]->x-200;
             for(int i=0;i<enemigos.size();i++)
           enemigos[i]->x=enemigos[i]->x-200;

        }
      }



        if (cursor_nivel_x==0)
        for (int x=0;x<vida_easy;x++)
        apply_surface(x*35,0,corazon,screen);
        else if (cursor_nivel_x==1)
            for (int x=0;x<vida_mediun;x++)
        apply_surface(x*35,0,corazon,screen);
        else if (cursor_nivel_x==2)
            for (int x=0;x<vida_hard;x++)
        apply_surface(x*35,0,corazon,screen);

        if (personaje->x>puerta_x&&personaje->x<puerta_x+60&&personaje->y+50>puerta_y&&personaje->y+50<puerta_y+49){
            apply_surface(0,0,ganador,screen);
            ganar=true;
            tiempo_de_espera_de_ganar++;
        }
        if (vida_easy==0||vida_hard==0||vida_mediun==0){
            apply_surface(0,0,perdio,screen);
            perder=true;
             tiempo_de_espera_de_ganar++;

        }
         apply_surface(105,0,puntuacion_texto,screen);

        if (tiempo_de_espera_de_ganar==50){
            escritura_puntaje.seekp(escritura_puntaje.eof());
            escritura_puntaje<<puntuacion<<std::endl;

            escritura_puntaje.close();
             tiempo_de_espera_de_ganar=0;
             personaje->x=0;
             personaje->y=450;
             puntuacion=0;
             vida_easy=3;
             vida_mediun=2;
             vida_hard=1;
             menu_bool=true;
             ganar=false;
             perder=false;
             nivel_bool=true;
             jugar=false;
        if (personaje->x==0&&movimiento_de_pantalla==true){
            movimiento_de_pantalla=false;
            menu_x+=200;
            puerta_x+=200;
            for(int i=0;i<plataformas.size();i++)
            plataformas[i]->reset();
           for(int i=0;i<enemigos.size();i++)
            enemigos[i]->reset();
        }else{
        for(int i=0;i<plataformas.size();i++)
            plataformas[i]->reset();
           for(int i=0;i<enemigos.size();i++)
            enemigos[i]->reset();
        }

        }



        if (personaje->x<0&&movimiento_de_pantalla==true){
          movimiento_de_pantalla=false;
            personaje->x+=200;
            menu_x+=200;
            puerta_x+=200;
            for(int i=0;i<plataformas.size();i++)
            plataformas[i]->reset();
            for(int i=0;i<enemigos.size();i++)
        enemigos[i]->reset();

        }

        if (personaje->x>=500&&movimiento_de_pantalla==false){
          movimiento_de_pantalla=true;
            personaje->x-=200;
            menu_x-=200;
            puerta_x-=200;
            for(int i=0;i<plataformas.size();i++)
           plataformas[i]->x=plataformas[i]->x-200;
             for(int i=0;i<enemigos.size();i++)
           enemigos[i]->x=enemigos[i]->x-200;

        }
       if (personaje->saltar==true){
       personaje->y--;
       saltar++;
       personaje->y--;
       saltar++;
       personaje->y--;
       saltar++;
       if (saltar>=100){
        personaje->saltar=false;
        saltar=0;
       }
       }
         if (personaje->saltar==false&&personaje->y<=435){
            personaje->y++;
         }

        }

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
        if( event.type == SDL_KEYDOWN )
            {

               switch( event.key.keysym.sym )
                {
                    case SDLK_SPACE:
                        if (personaje->saltar==false){
                        personaje->y--;
                        personaje->y--;
                        personaje->saltar=true;

                        }

                    break;
                    case SDLK_UP:
                        if (jugar==true&&ganar==false&&perder==false){
                     personaje->y--;
                     personaje->y--;
                        }
                    break;
                    case SDLK_DOWN:
                        if (jugar==true&&ganar==false&&perder==false){
                     personaje->y++;
                     personaje->y++;
                        }
                    break;
                    case SDLK_ESCAPE:
                     cursor_x=0;
                        nivel_bool=true;
                        menu_bool=true;

                    break;
                    case SDLK_RETURN:
                       if (menu_bool==true){
                        menu_bool=false;
                       }else if (menu_bool==false&&nivel_bool==true){
                        nivel_bool=false;

                       }else if (menu_bool==false&&nivel_bool==false&&jugar==false){
                       jugar=true;

                       }

                    break;
                    case SDLK_RIGHT:

                         if (menu_bool==true){
                        cursor_x++;
                       }else if(nivel_bool==true){
                        cursor_nivel_x++;
                       }else if (jugar==true&&ganar==false&&perder==false){
                       personaje->tiempo++;
                       personaje->x++;

                        if (personaje->tiempo==5&&personaje->saltar==false){
                            if (personaje->cuadro_actual==0){
                                personaje->cuadro_actual=1;
                            }

                            }
                            if (personaje->tiempo==10&&personaje->saltar==false){
                                if (personaje->cuadro_actual==1)
                                personaje->cuadro_actual=0;
                            personaje->tiempo=0;

                            }if (personaje->saltar==true){
                                personaje->cuadro_actual=4;
                                personaje->tiempo=0;
                            }else if (personaje->saltar==false&&personaje->tiempo==0){
                            personaje->cuadro_actual=0;
                            }
                       puntuacion++;
                       }

                    break;
                    case SDLK_LEFT:

                        if (menu_bool==true){
                        cursor_x--;
                       }else if(nivel_bool==true){
                        cursor_nivel_x--;
                       }else if (jugar==true&&ganar==false&&perder==false){

                        personaje->tiempo++;
                       personaje->x--;

                        if (personaje->tiempo==5&&personaje->saltar==false){
                            if (personaje->cuadro_actual==2){
                                personaje->cuadro_actual=3;
                            }

                            }
                            if (personaje->tiempo==10&&personaje->saltar==false){
                                if (personaje->cuadro_actual==3)
                                personaje->cuadro_actual=2;
                            personaje->tiempo=0;

                            }
                             if (personaje->saltar==true){
                                personaje->cuadro_actual=5;
                                 personaje->tiempo=0;

                            }else if(personaje->saltar==false&&personaje->tiempo==0)
                            personaje->cuadro_actual=2;

                       puntuacion--;
                       }

                    break;
                }
            }

            }


    //Clean up
    clean_up();

    return 0;
}
