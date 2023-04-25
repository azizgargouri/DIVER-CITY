#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "function.h"



 
 void initialiser_imageBACK_P(image *imge)
 {
 
 
 imge->url="OptionFinal.jpg";
 imge->img=IMG_Load(imge->url);
 if (imge->img == NULL) {
 printf("unable to load background image %s \n", SDL_GetError());
 return ; }
 imge->pos_img_ecran.x=0;
 imge->pos_img_ecran.y=0;
 imge->pos_img_affiche.x=0;
 imge->pos_img_affiche.y=0;
 imge->pos_img_affiche.h=SCREEN_H;
 imge->pos_img_affiche.w=SCREEN_W;
 }
 

 void afficher_imageBMP_P(SDL_Surface *screen, image imge)
 {
 SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
 }
 




void afficheoptionsbg(SDL_Surface *screen)
{
image IMAGE_P;
Mix_Music *music;
Mix_Chunk *mus;
SDL_Event event;
int boucle=1;

//inisalisation de la SDL
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
}
//reglage de la fenetre
screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H, 32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
//initialistion

initialiser_imageBACK_P(&IMAGE_P);


float sound=3.5;

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {
  printf("%s",SDL_GetError());
  }
  music=Mix_LoadMUS("Bastion.mp3");
  Mix_PlayMusic(music,-1);
  

//boucle du menu

while(boucle)
 {
//L'affichage

afficher_imageBMP_P(screen, IMAGE_P);


while(SDL_PollEvent(&event))
  {
switch(event.type)
   {
  case SDL_QUIT:
  boucle=0;
  break;
   
   case SDL_MOUSEBUTTONDOWN: //return to main menu button

    if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=430 && event.motion.y>=350 && event.motion.x<=670 && event.motion.x>=640))
    affichemenu(screen);//return to main menu

    break;
    
   case SDL_KEYDOWN:
   if(event.key.keysym.sym==SDLK_o) // Sound +
   {
    sound=sound-3.5;
    Mix_VolumeMusic(MIX_MAX_VOLUME/sound);
   }

   if(event.key.keysym.sym==SDLK_i) // Sound -
   {
    sound=sound+3.5;
    Mix_VolumeMusic(MIX_MAX_VOLUME/sound);
   }
   
   if(event.key.keysym.sym==SDLK_ESCAPE) // Return to menu
   {
    affichemenu(screen);
   }
   break;
  
   
   
   
   }
  }
  
  SDL_Flip(screen); //Screen refreshing
 }
//Surfaces liberation

liberer_image(IMAGE_P);

//Music liberation
liberer_musique(music);

//Quitting the SDL
SDL_Quit();
}




 
