#include <stdio.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#define W_Ecran 1920//1200
#define H_Ecran 1080//560

#define W_ImageBack 6700
#define H_ImageBack 560

struct Personne
{
   
       	SDL_Surface *image;
	SDL_Rect position;
	SDL_Rect frame;
	
	int curframe; 
	int direction;  
        int running;	 	 
	double vitesse;
        double x;
	double grav ;
	double saut ;
	double y ;    
	
} ;
typedef struct Personne Personne ;

void initPerso(Personne *p) ;
void initPerso2(Personne *p2) ;
void afficherPerso (Personne p,SDL_Surface *screen) ;
void deplacerperso(Personne *p,int dt)  ;
void animerPerso(Personne *p) ;
void saut(Personne *p) ;
