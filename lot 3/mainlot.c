#include <stdio.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"es.h"


int main()
{
 
  Ennemi e;
  SDL_Surface *backg;
   SDL_Rect pos_backg ;
  SDL_Surface *screen;
  SDL_Event event;
  
  int done =1,g ;


  SDL_Init( SDL_INIT_VIDEO);  
       
        screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H, 32,SDL_HWSURFACE | SDL_SRCALPHA|SDL_DOUBLEBUF|SDL_RESIZABLE); //588,294
          	if( !screen)
        {
		printf("unable to set 1920*1080: %s\n",SDL_GetError());
		return 1; 
        }

backg = IMG_Load("tokyo.png");  //backg

	pos_backg.x=0;
	pos_backg.y=0;

   initEnnemi (&e);
     
    //SDL_EnableKeyRepeat(10, 0);
   //printf("1.joueur 1 \n") ;
   //printf("2.jouers 2 \n") ;
  // scanf("%d",&g);
   
     while(done)
{
  SDL_BlitSurface(backg,NULL,screen,&pos_backg);
  afficherEnnemi(e,screen); 
 
 /* e.pos_frame.w=66.667 ;
  e.pos_frame.h=100 ;
  e.pos_frame.x=0 ;
  e.pos_frame.y=0 ;
  e.direction=1 ;
  */
 

  
    //saut(&e);

 

  
   
   SDL_Flip(screen);
   SDL_PollEvent(&event);

      switch(event.type)
      {
           case SDL_QUIT :
           SDL_FreeSurface(screen);
           done = 0;
           break ;
       

          case SDL_KEYDOWN:
               switch(event.key.keysym.sym)
                 {  
                      
                   case SDLK_UP:
               /* e.pos_frame.w=66.667 ;
                     e.pos_frame.h=100 ;
                     e.pos_frame.x=0 ;
                     e.pos_frame.y=0 ;
                     animerEnnemi(&e);
                     e.direction=1 ;
  
 
                   

                     if (e.pos_ennemi[0][0].x==520)
                     { 
                        e.direction=2 ;
                        e.pos_frame.w=66.667 ;
                        e.pos_frame.h=200 ;
                        e.pos_frame.x=333.335 ;
                        e.pos_frame.y=115 ;

                     } */
              
              
              
              
              
              animerEnnemi(&e);
             
                  // deplacerperso(&p,p.direction) ; 
                 move(&e);

                   break ; 

                 case SDLK_DOWN:
                 e.pos_frame.w=66.667;
                 e.pos_frame.h=200;
                 e.pos_frame.x=333.335;
                 e.pos_frame.y=115;
                 animerEnnemi(&e);
                 e.direction=2;
 
                 if (e.pos_ennemi[0][0].x==0)
                 {
                e.direction=1 ;
                e.pos_frame.w=66.667;
                e.pos_frame.h=100;
                e.pos_frame.x=0;
                e.pos_frame.y=0;
                  }
              move(&e);
               break;
               
         case SDLK_u:
         //p.vitesse= p.vitesse+0.1;
          break ; 

          case SDLK_i:
         //if(p.vitesse>=1)
         //p.vitesse= p.vitesse-0.1;
          break ;
          case SDLK_SPACE:
           e.pos_ennemi[0][0].y-=0.5;
            
            
                   
          
            break ;
            if (g==2||g==1)
         {
             case SDLK_d:
                   e.pos_frame.w=66.667 ;
                     e.pos_frame.h=100 ;
                     e.pos_frame.x=0 ;
                     e.pos_frame.y=0 ;
                     animerEnnemi(&e) ;
                     e.direction=1 ; 
            
            
                   
 
                   /*  if (e.pos_ennemi[0][0].x==520)
                     { 
                        e.direction=2 ;
                        e.pos_frame.w=66.667 ;
                        e.pos_frame.h=200 ;
                       e.pos_frame.x=333.335 ;
                        e.pos_frame.y=115 ;

                     }*/
             
                   //deplacerperso(&e2,e.direction) ; 
                   break ;
             case SDLK_s :
                 e.pos_frame.w=66.667;
                 e.pos_frame.h=200;
                 e.pos_frame.x=333.335;
                 e.pos_frame.y=115;
                  animerEnnemi(&e);
                 e.direction=2;
 
                 if (e.pos_ennemi[0][0].x==0)
                 {
                e.direction=1;
                e.pos_frame.w=66.667;
                e.pos_frame.h=100;
                e.pos_frame.x=0;
                e.pos_frame.y=0;
                  }
              //deplacerperso(&p2,p2.direction) ;
            break ;
         }
 

           
      
  break ;

      } 
 
 

}
	
}
SDL_Flip(screen);
return 0  ;
}




