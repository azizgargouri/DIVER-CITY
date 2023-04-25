#ifndef FUNCTION_H
#define FUNCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 1080
#define SCREEN_W 1920
typedef struct
{
 char *url;
 SDL_Rect pos_img_affiche; // The Displayed part of the image
 SDL_Rect pos_img_ecran; // Image Position
 SDL_Surface *img;
}image;

typedef struct
{
 SDL_Surface *txt; 
 SDL_Rect pos_txt; 
 SDL_Colour color_txt;
 TTF_Font *police;
}texte;

//Image
void initialiser_imageBACK(image *imge);
void initialiser_imageBACK_P(image *imge);
void initialiser_imageBACK_O(image *imge);
void initialiser_imageBOUTON1(image *imgbtn);
void initialiser_imageBOUTON1v2(image *imgbtn);
void initialiser_imageBOUTON2(image *imgbtn);
void initialiser_imageBOUTON2v2(image *imgbtn);
void initialiser_imageBOUTON3(image *imgbtn);
void initialiser_imageBOUTON3v2(image *imgbtn);
void initialiser_MB(image *imgbtn);

void afficheoptionsbg(SDL_Surface *screen);
void afficheplaybg(SDL_Surface *screen);
void affichemenu(SDL_Surface *screen);
void afficher_imageBMP(SDL_Surface *screen, image imge);
void afficher_imageBMP_P(SDL_Surface *screen, image imge);
void afficher_imageBMP_O(SDL_Surface *screen, image imge);
void afficher_imageBTN1(SDL_Surface *screen, image imge);
void afficher_imageBTN1v2(SDL_Surface *screen, image imge);
void afficher_imageBTN2(SDL_Surface *screen, image imge);
void afficher_imageBTN2v2(SDL_Surface *screen, image imge);
void afficher_imageBTN3(SDL_Surface *screen, image imge);
void afficher_imageBTN3v2(SDL_Surface *screen, image imge);
void afficher_minibutton(SDL_Surface *screen, image imge);
void liberer_image(image imge);


//Audio
void initialiser_audio(Mix_Music *music);
void liberer_musique(Mix_Music *music);

void initialiser_audiobref(Mix_Chunk *music);
void liberer_musiquebref(Mix_Chunk *music);

//Text
void initialiser_texte(texte *txte);
void afficher_texte(SDL_Surface *screen, texte txte);
void liberer_texte(texte txte);

#endif

