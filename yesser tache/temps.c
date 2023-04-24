#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "temps.h"
//#include "time.h"

void initialiser_temps(temps *t)
{
 t->texte = NULL; 
 t->position.x=30;
   t->position.y=30;
     t->police = NULL;
  t->police = TTF_OpenFont("avocado.ttf", 30);
    strcpy( t->entree,"");
(t->secondesEcoulees)=0;
time(&(t->t1)); 

}

void afficher_temps(temps *t,SDL_Surface *ecran)
{	
SDL_Color couleurBlanche= {0, 0, 0};

    	time(&(t->t2));

		t->secondesEcoulees = t->t2 - t->t1;

        t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);

	 sprintf(t->entree,"%02d:%02d",t->min,t->sec);
        t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurBlanche);
      
SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); 
  	
}

void free_temps(temps *t,SDL_Surface *ecran)
{SDL_FreeSurface(t->texte);
 TTF_CloseFont(t->police);
}
