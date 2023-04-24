#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img;
}image;

typedef struct
{
SDL_Surface *reponses[3], *quest;
SDL_Rect PosQuestion;
SDL_Rect PosReponse[3];
int choix_question;
char question[150];
char reponseA[50];
char reponseB[50];
char reponseC[50];
int correctAnswer;
}enigme;

void initialiser_audio(Mix_Music *music);
void liberer_musique(Mix_Music *music);
void initialiser_imagequestion(image boutoun[],image repp[],image longbouton[]); //
void afficherbutton(image i, SDL_Surface *screen);
void liberer_image(image imge);
void generer(enigme *e ,char *nomfichier);
void afficherenigme(enigme *e,SDL_Surface *screen);
void menigme (enigme *e);
void inithorloge(SDL_Surface *horloge[]);
#endif
