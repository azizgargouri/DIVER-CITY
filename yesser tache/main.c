/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "minimap.h"
#include "temps.h"
//#include "time.h"
#include "score.h"
#include "save.h"

int main()
{
    TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen ,*perso;
screen=SDL_SetVideoMode (750,604,32,SDL_HWSURFACE|SDL_DOUBLEBUF); 
 SDL_WM_SetCaption("minimap",NULL);
SDL_Rect camera,posperso;
SDL_Event event;
minimap m;
temps t;
SDL_Surface *back;
perso=IMG_Load("hero.png");
back=IMG_Load("map.jpg");
int continuer=1;
init_map(&m);
camera.x=0;
camera.y=0;
camera.w=1366;
camera.h=768;
posperso.x=0;
posperso.y=260;
SDL_EnableKeyRepeat(100,10);
initialiser_temps(&t);

int valeur_score=0;
score s;
initialiser_score(valeur_score,&s);
while(continuer)
{  
    SDL_BlitSurface(back,NULL,screen,NULL);
while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_ESCAPE:
					save(valeur_score);
					
					           continuer = 0;
				                 break;
                case SDLK_p:
						update_score(&valeur_score);
						break;
                case SDLK_LEFT:
                
                     posperso.x-=2;
                
                    
                break;
                case SDLK_RIGHT:
                  
                      posperso.x+=2;
                    
                break;
                case SDLK_UP:
              
                      posperso.y-=2;
                break;  
                case SDLK_DOWN:
                    
                      posperso.y+=2;

                break;  
            }
            break;           
        }
    }        
SDL_BlitSurface(perso,NULL,screen,&posperso);


MAJMinimap(posperso ,  &m, camera, 20);
afficherminimap(m,screen);

afficher_temps(&t,screen);
afficher_score(&s,screen,valeur_score);

SDL_Flip(screen);

}

    
}


