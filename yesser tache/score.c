#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "score.h"

void initialiser_score (int valeur_score, score *s )
{
SDL_Surface *texte1=NULL; 
SDL_Surface *number1=NULL;
TTF_Font *police=NULL;

s->police = TTF_OpenFont("angelina.TTF", 60);

SDL_Color couleur={0,0,0}; 

s->position_number.x=700;
s->position_number.y=0;

s->position_texte.x=600;
s->position_texte.y=0;
char texte[20];

strcpy(texte,"Score :"); 

char number[20]; 

sprintf(number, "%d ", valeur_score);
s->texte1= TTF_RenderText_Blended(s->police,texte,couleur);
s->number1= TTF_RenderText_Blended(s->police,number,couleur);
TTF_CloseFont(police);

}

// AFFICHAGE
void afficher_score(score *s,SDL_Surface *screen,int valeur_score)
{
SDL_Color couleur={0,0,0};
char texte[20];
strcpy(texte,"score :");  

char number[20]; 
sprintf(number, "%d ", valeur_score); 
s->texte1= TTF_RenderText_Blended(s->police,texte,couleur);
s->number1= TTF_RenderText_Blended(s->police,number,couleur);
 SDL_BlitSurface(s->texte1, NULL, screen,&s->position_texte);
SDL_BlitSurface(s->number1, NULL, screen,&s->position_number);
}

void update_score  (int *valeur_score)
{
  	(*valeur_score)+=5;	

}

void free_score( score s)
{
SDL_FreeSurface(s.texte1);
SDL_FreeSurface(s.number1);

}
  
