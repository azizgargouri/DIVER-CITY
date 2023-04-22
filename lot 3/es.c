#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "es.h"

void initEnnemi (Ennemi *e)

{

   //e->pos.x=0;
   //e->pos.y=0;
    //e->pos_ennemi.w=(SCREEN_W);
   //e->pos_ennemi.h=(SCREEN_H);
   
   e->pos_ennemi[0][0].x=0;
   e->pos_ennemi[0][0].y=0;
   e->pos_ennemi_absolue.x=0;
   e->pos_ennemi_absolue.y=0;
    
   
   
   e->direction=0;
   e->collision=0;
   
    //e->pos.vitesse=0;
   //e->pos.acceleration=0;

   e->image_ennemi[0][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk1.png"); 
    e->pos_ennemi[0][0].x=500;
   e->pos_ennemi[0][0].y=500;

   e->image_ennemi[1][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk2.png");
   e->pos_ennemi[1][0].x=1000;
   e->pos_ennemi[1][0].y=600;

   
   e->image_ennemi[2][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk3.png");
    e->pos_ennemi[2][0].x=600;
   e->pos_ennemi[2][0].y=600;
   
   e->image_ennemi[3][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk4.png");
    e->pos_ennemi[3][0].x=500;
  e->pos_ennemi[3][0].y=500;
   
   e->image_ennemi[4][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk5.png");
   e->image_ennemi[5][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk6.png");
   e->image_ennemi[6][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk7.png");
   e->pos_ennemi[6][0].x=600;
   e->pos_ennemi[6][0].y=550;
   
   e->image_ennemi[7][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk8.png");
   e->pos_ennemi[7][0].x=500;
   e->pos_ennemi[7][0].y=500;
   
   
   e->image_ennemi[0][1]=IMG_Load("knightR1.png"); 
   e->image_ennemi[1][1]=IMG_Load("knightR1.png"); 
   e->image_ennemi[2][1]=IMG_Load("knightR2.png");
   e->image_ennemi[3][1]=IMG_Load("knightR3.png");
   e->image_ennemi[4][1]=IMG_Load("knightR4.png");
   e->image_ennemi[5][1]=IMG_Load("knightR5.png");
   e->image_ennemi[6][1]=IMG_Load("knightR6.png"); 
   e->image_ennemi[7][1]=IMG_Load("knightR7.png");
   
   
  // e->image_ennemi[0][0]->pos_ennemi.x=500;
  // e->image_ennemi[0][0]->pos_ennemi.y=500;


}

   void afficherEnnemi(Ennemi e, SDL_Surface  * screen)        
   {                                                          
   //&imge.pos_img_ecran
   //SDL_BlitSurface(image.img,&imge.pos_img_affiche,screen,&e.pos_ennemi );
   
   SDL_BlitSurface(e.image_ennemi[0][0],NULL, screen, &e.pos_ennemi[0][0]);
   
   }
   
   
   
   
   void animerEnnemi( Ennemi * e)
   {  
   int i,j;
   double vitesse=0.5;


 e->image_ennemi[0][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk1.png"); 
 
    e->pos_ennemi[0][0].x=500+vitesse;
   e->pos_ennemi[0][0].y=500;
     
    e->image_ennemi[1][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk2.png");
    e->pos_ennemi[1][0].x=510+vitesse;
   e->pos_ennemi[1][0].y=500;
   
    e->image_ennemi[2][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk3.png");
    e->pos_ennemi[2][0].x=520+vitesse;
   e->pos_ennemi[2][0].y=500;

    e->image_ennemi[3][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk4.png");
    e->pos_ennemi[3][0].x=530+vitesse;
   e->pos_ennemi[3][0].y=500;
  
    e->image_ennemi[4][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk5.png");
    e->pos_ennemi[4][0].x=540+vitesse;
   e->pos_ennemi[4][0].y=500;
 
   e->image_ennemi[5][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk6.png");
    e->pos_ennemi[5][0].x=550+vitesse;
   e->pos_ennemi[5][0].y=500;
   
   e->image_ennemi[6][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk7.png");
    e->pos_ennemi[6][0].x=560+vitesse;
   e->pos_ennemi[6][0].y=500;
   
   e->image_ennemi[7][0]=IMG_Load("/home/aziz/Desktop/lot 3/walk/walk8.png");
    e->pos_ennemi[7][0].x=570+vitesse;
   e->pos_ennemi[7][0].y=500;
 

/*for(j=0; j<2; j++)
{
   

}
} 
if (e->direction == 0)
	{ 
		if (e->pos_frame.x<5)
		{
		
                e->pos_frame.x++;
                SDL_Delay(25);  
		}
		else 
		{
		e->pos_frame.x =0;
		}
	}
	else if (e->direction==1)
	{
		if (e->pos_frame.x<3)
		{
		e->pos_frame.x++;
		SDL_Delay(25);
		}
		else 
		{
		e->pos_frame.x=0;
		}
	}
  
   
   
 */  
   
   }
   
   /*void move( Ennemi * e)
   {
   int posmax=600,posmin=40;
   
   if((*e).pos_ennemi_absolue.x==posmax)	(*e).direction=1 ;
		
		if((*e).pos_ennemi_absolue.x==posmin) (*e).direction=0;
		
		
		
		
		if((*e).direction==1)	(*e).pos_ennemi_absolue.x--;
		
		//else	(*e).pos_ennemi_absolue.x++;
		else if((*e).direction==0)	(*e).pos_ennemi_absolue.x++;

   
   
   }
   
   /*int collisionBB( Ennemi * e ,SDL_Rect posp,  SDL_Rect pose)
   {
   int collision;
    if ((e->pos_ennemi.x + e->pos_ennemi.w < e->pos_ennemi.x) || (e->pos_ennemi.x > pose.x + e->pos_ennemi.w) || 
        (e->pos_ennemi.y + e->pos_ennemi.h < e->pos_ennemi.y) || (e->pos_ennemi.y > e->pos_ennemi.y + e->pos_ennemi.h)) 
       {
        e->collision = 0; // pas de collision
    } else 
    {
        collision = 1;
    }
    return collision;
}
 void moveIA( Ennemi * e)
 {
 
 
 }
   
   
  /* void liberer_image(Ennemi *e)
{
SDL_FreeSurface(e->Ennemi );
}*/
