#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "save.h"



void save (int valeur_score)
 { 
    FILE* saveF = NULL;
    saveF = fopen("sauvegarde.txt","w+"); 

        if(saveF != NULL)
{   

 fprintf(saveF,"%d\n",valeur_score); 
              
        }

    fclose(saveF); 
}
void load (int valeur_score )
{ 

    FILE* saveF = NULL;
    saveF = fopen("sauvegarde.txt","r"); 

    if(saveF != NULL) 
	{ 
	
	    fscanf(saveF,"%d",&valeur_score);   
}

    fclose(saveF); 
}
