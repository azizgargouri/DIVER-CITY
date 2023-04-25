#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "function.h"


int main()
{
//Declaration des variables
SDL_Surface *screen;
SDL_Surface *screen2;
SDL_Surface *screen3;
image IMAGE, IMAGE_P, IMAGE_O,  IMAGE_BTN1, IMAGE_BTN1v2, IMAGE_BTN2, IMAGE_BTN2v2, IMAGE_BTN3, IMAGE_BTN3v2;
Mix_Music *music;
Mix_Chunk *mus;
texte txte;
SDL_Event event;
TTF_Init();
int boucle=1;

//inisalisation de la SDL
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER|SDL_RESIZABLE)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}
//reglage de la fenetre
screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H, 32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
//initialistion
initialiser_imageBACK(&IMAGE);
initialiser_imageBACK_P(&IMAGE_P);
initialiser_imageBACK_O(&IMAGE_O);
initialiser_imageBOUTON1(&IMAGE_BTN1);
initialiser_imageBOUTON1v2(&IMAGE_BTN1v2);
initialiser_imageBOUTON2(&IMAGE_BTN2);
initialiser_imageBOUTON2v2(&IMAGE_BTN2v2);
initialiser_imageBOUTON3(&IMAGE_BTN3);
initialiser_imageBOUTON3v2(&IMAGE_BTN3v2);
initialiser_audio(music);
initialiser_texte(&txte);

//boucle du menu

while(boucle)
 {
//L'affichage

afficher_imageBMP(screen, IMAGE);
afficher_imageBTN1(screen, IMAGE_BTN1);
afficher_imageBTN2(screen, IMAGE_BTN2);
afficher_imageBTN3(screen, IMAGE_BTN3);
afficher_texte(screen, txte);
while(SDL_PollEvent(&event))
  {
switch(event.type)
   {
  case SDL_QUIT:
  boucle=0;
  break;
   
  case SDL_MOUSEMOTION: //Sound and displaying of buttons
  
  if ( (event.motion.y<=600 && event.motion.y>=500 && (event.motion.x<=1060 && event.motion.x>=860)) )
  initialiser_audiobref(mus), afficher_imageBTN1v2(screen, IMAGE_BTN1v2);//Play a sound & affiche Play2 button 

  if ( (event.motion.y<=720 && event.motion.y>=630 && (event.motion.x<=1060 && event.motion.x>=860))  )
  initialiser_audiobref(mus), afficher_imageBTN3v2(screen, IMAGE_BTN3v2); //Play a sound & affiche Option2 button
  
  if ( (event.motion.y<=860 && event.motion.y>=770 && (event.motion.x<=1060 && event.motion.x>=860))  )
  initialiser_audiobref(mus), afficher_imageBTN2v2(screen, IMAGE_BTN2v2); //Play a sound & affiche Quit2 button 
  
  break;
  
  case SDL_MOUSEBUTTONDOWN: // Quitting and Displaying backgrounds of Play button and Options button
  
 
  if (event.motion.y<=600 && event.motion.y>=500 && (event.motion.x<=1060 && event.motion.x>=860))
    afficheplaybg(screen);//Displaying of the Play Background
    
   if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=720 && event.motion.y>=630 && (event.motion.x<=1060 && event.motion.x>=860)))
    afficheoptionsbg(screen);//Displaying of the Options Background
   
   if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=860 && event.motion.y>=770 && (event.motion.x<=1060 && event.motion.x>=860)))
   boucle=0; //Quitting the menu
   
   break;
   
   case SDL_KEYDOWN:
   if(event.key.keysym.sym==SDLK_q)
   {
     boucle=0;
   }
   break;
   }
  }
  
  SDL_Flip(screen); //Screen refreshing
 }
//Surfaces liberation
liberer_image(IMAGE);
liberer_image(IMAGE_P);
liberer_image(IMAGE_O);
liberer_image(IMAGE_BTN1);
liberer_image(IMAGE_BTN1v2);
liberer_image(IMAGE_BTN2);
liberer_image(IMAGE_BTN2v2);
liberer_image(IMAGE_BTN3);
liberer_image(IMAGE_BTN3v2);

//Music liberation
liberer_musique(music);
liberer_musiquebref(mus);

//Text liberation
liberer_texte(txte);
//Quitting the SDL
SDL_Quit();
return 0;
}
