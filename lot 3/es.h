
#define FUNCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>  
#define SCREEN_H 1080
#define SCREEN_W 1920

/*typedef struct
{                            
SDL_Surface* ENNEMI;  
int direction;
SDL_Rect postScreen;

SDL_Rect posEnnemi;
double vitesse;
double acceleration;
int direction;
int collision;

}Ennemi;
*/


typedef struct 
{
	SDL_Surface* image_ennemi[8][2];
	SDL_Rect pos_ennemi[8];
        SDL_Rect pos_ennemi_absolue;
	SDL_Rect pos_frame;
	int direction;
	int collision;
	
}Ennemi;





void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e, SDL_Surface  * screen);
void animerEnnemi( Ennemi * e);
void move( Ennemi * e);
 int collisionBB( Ennemi * e ,SDL_Rect posp,  SDL_Rect pose);
 void moveIA( Ennemi * e); 
