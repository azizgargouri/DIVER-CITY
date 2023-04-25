#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "function.h"

void initialiser_imageBACK(image *imge)
 {
 
 
 imge->url="Menu sdl.jpg";
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
 
 


void initialiser_imageBOUTON1(image *imgbtn)
 {
imgbtn->url="Play.png";
imgbtn->img=IMG_Load(imgbtn->url);
if (imgbtn->img == NULL) {
printf("unable to load background image %s \n",SDL_GetError());
return ;}

imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=imgbtn->img->w;
imgbtn->pos_img_affiche.h=imgbtn->img->h;
imgbtn->pos_img_ecran.x=((2830-imgbtn->pos_img_affiche.w)/3);
imgbtn->pos_img_ecran.y=((1600-imgbtn->pos_img_affiche.h)/3);

 }
 
 void initialiser_imageBOUTON1v2(image *imgbtn)
 {
imgbtn->url="Play2.png";
imgbtn->img=IMG_Load(imgbtn->url);
if (imgbtn->img == NULL) {
printf("unable to load background image %s \n",SDL_GetError());
return ;}

imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=imgbtn->img->w;
imgbtn->pos_img_affiche.h=imgbtn->img->h;
imgbtn->pos_img_ecran.x=((2830-imgbtn->pos_img_affiche.w)/3);
imgbtn->pos_img_ecran.y=((1600-imgbtn->pos_img_affiche.h)/3);

 }
 void initialiser_imageBOUTON3(image *imgbtn)
 {
imgbtn->url="Options.png";
imgbtn->img=IMG_Load(imgbtn->url);
if (imgbtn->img == NULL) {
printf("unable to load background image %s \n",SDL_GetError());
return ;}

imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=imgbtn->img->w;
imgbtn->pos_img_affiche.h=imgbtn->img->h;
imgbtn->pos_img_ecran.x=((2830-imgbtn->pos_img_affiche.w)/3);
imgbtn->pos_img_ecran.y=((2000-imgbtn->pos_img_affiche.h)/3);

 }
 
 void initialiser_imageBOUTON3v2(image *imgbtn)
 {
imgbtn->url="Options2.png";
imgbtn->img=IMG_Load(imgbtn->url);
if (imgbtn->img == NULL) {
printf("unable to load background image %s \n",SDL_GetError());
return ;}

imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=imgbtn->img->w;
imgbtn->pos_img_affiche.h=imgbtn->img->h; 
imgbtn->pos_img_ecran.x=((2830-imgbtn->pos_img_affiche.w)/3);
imgbtn->pos_img_ecran.y=((2000-imgbtn->pos_img_affiche.h)/3);

 }
 
 void initialiser_imageBOUTON2(image *imgbtn)
 {
imgbtn->url="Quit.png";
imgbtn->img=IMG_Load(imgbtn->url);
if (imgbtn->img == NULL) {
printf("unable to load background image %s \n",SDL_GetError());
return ;}

imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=imgbtn->img->w;
imgbtn->pos_img_affiche.h=imgbtn->img->h; 
imgbtn->pos_img_ecran.x=((2830-imgbtn->pos_img_affiche.w)/3);
imgbtn->pos_img_ecran.y=((2400-imgbtn->pos_img_affiche.h)/3);

 }
 
 void initialiser_imageBOUTON2v2(image *imgbtn)
 {
imgbtn->url="Quit2.png";
imgbtn->img=IMG_Load(imgbtn->url);
if (imgbtn->img == NULL) {
printf("unable to load background image %s \n",SDL_GetError());
return ;}

imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=imgbtn->img->w;
imgbtn->pos_img_affiche.h=imgbtn->img->h; 
imgbtn->pos_img_ecran.x=((2830-imgbtn->pos_img_affiche.w)/3);
imgbtn->pos_img_ecran.y=((2395-imgbtn->pos_img_affiche.h)/3);

 }

void afficher_imageBMP(SDL_Surface *screen, image imge)
 {
 SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
 }
 
void afficher_imageBTN1(SDL_Surface *screen, image imge)
 {
 SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
 }
 void afficher_imageBTN1v2(SDL_Surface *screen, image imge)
 {
 SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
 }
void afficher_imageBTN2(SDL_Surface *screen, image imge)
 {
 SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
 }
 void afficher_imageBTN2v2(SDL_Surface *screen, image imge)
 {
 SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
 }
 void afficher_imageBTN3(SDL_Surface *screen, image imge)
 {
 SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
 }
 void afficher_imageBTN3v2(SDL_Surface *screen, image imge)
 {
 SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
 }
void liberer_image(image imge)
 {
 SDL_FreeSurface(imge.img);
 }



void initialiser_audio(Mix_Music *music)
 {
 if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {
  printf("%s",SDL_GetError());
  }
  music=Mix_LoadMUS("Bastion.mp3");
  Mix_PlayMusic(music,-1);
  Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
 }
void liberer_musique(Mix_Music *music)
 {
 Mix_FreeMusic(music);
 }
void initialiser_audiobref(Mix_Chunk *music)
 {
 Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2, 2048);
 music = Mix_LoadWAV("c1.wav");
 Mix_PlayChannel(-1,music, 0);
 if (music==NULL) 
 printf("%s",SDL_GetError());
  
 }
void liberer_musiquebref(Mix_Chunk *music)
 {
 Mix_FreeChunk(music);
 }
 
void initialiser_texte(texte *txte)
 {
  txte->police = TTF_OpenFont("v.ttf",55);
  txte->color_txt.r=0;
  txte->color_txt.g=0;
  txte->color_txt.b=0;
  
   txte->pos_txt.x=415;
   txte->pos_txt.y=35;
 }
void afficher_texte(SDL_Surface *screen, texte txte)
 {
  txte.txt=TTF_RenderText_Blended(txte.police, "",txte.color_txt);
  SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
 }
void liberer_texte(texte txte)
 {
  TTF_CloseFont(txte.police);
  TTF_Quit();
 }
void affichemenu(SDL_Surface *screen)
{
//Declaration des variables
image IMAGE, IMAGE_P, IMAGE_O, IMAGE_BTN1, IMAGE_BTN1v2, IMAGE_BTN2, IMAGE_BTN2v2, IMAGE_BTN3, IMAGE_BTN3v2;
Mix_Music *music;
Mix_Chunk *mus;
texte txte;
SDL_Event event;
TTF_Init();
int boucle=1;

//inisalisation de la SDL
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
}
//reglage de la fenetre
screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H, 32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
//initialistion
initialiser_imageBACK(&IMAGE);
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
  
  if ((event.motion.y<=600 && event.motion.y>=500 && (event.motion.x<=1060 && event.motion.x>=860)))
  initialiser_audiobref(mus), afficher_imageBTN1v2(screen, IMAGE_BTN1v2);//Play a sound & affiche Play2 button 

  if ((event.motion.y<=720 && event.motion.y>=630 && (event.motion.x<=1060 && event.motion.x>=860)))
  initialiser_audiobref(mus), afficher_imageBTN3v2(screen, IMAGE_BTN3v2); //Play a sound & affiche Option2 button
  
  if ((event.motion.y<=860 && event.motion.y>=770 && (event.motion.x<=1060 && event.motion.x>=860)))
  initialiser_audiobref(mus), afficher_imageBTN2v2(screen, IMAGE_BTN2v2); //Play a sound & affiche Quit2 button 
  
  break;
  
  case SDL_MOUSEBUTTONDOWN: // Quitting and Displaying backgrounds of Play button and Options button
  
 
  if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=600 && event.motion.y>=500 && (event.motion.x<=1060 && event.motion.x>=860)))
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
}
