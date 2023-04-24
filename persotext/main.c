#include <stdio.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"perso.h"


int main()
{
 
  Personne p ,p2;
  SDL_Surface *backg;
   SDL_Rect pos_backg ;
  SDL_Surface *screen;
  SDL_Event event;
  int done =1,g ;


  SDL_Init( SDL_INIT_VIDEO);
       
        screen = SDL_SetVideoMode(W_Ecran,H_Ecran, 32,SDL_HWSURFACE | SDL_SRCALPHA|SDL_DOUBLEBUF|SDL_RESIZABLE); //588,294
          	if( !screen)
        {
		printf("unable to set 1920*1080: %s\n",SDL_GetError());
		return 1; 
        }

backg = IMG_Load("tokyo.png");  //backg

	pos_backg.x=0;
	pos_backg.y=0;

    initPerso(&p) ;
     initPerso2(&p2) ;
    SDL_EnableKeyRepeat(10, 0);
   printf("1.joueur 1 \n") ;
   printf("2.jouers 2 \n") ;
   scanf("%d",&g);
   
     while(done)
{
  SDL_BlitSurface(backg,NULL,screen,&pos_backg);
  if(g==1)
{
   afficherPerso ( p,screen) ;
    saut(&p);
}
  if (g==2)
{
   afficherPerso ( p,screen) ;
   afficherPerso ( p2,screen) ;
}
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
              
                     p.frame.w=66.667 ;
                     p.frame.h=100 ;
                     p.frame.x=0 ;
                     p.frame.y=0 ;
                     animerPerso(&p) ;
                     p.direction=1 ;

                   
 
                     if (p.position.x==520)
                     { 
                        p.direction=2 ;
                        p.frame.w=66.667 ;
                        p.frame.h=200 ;
                        p.frame.x=333.335 ;
                        p.frame.y=115 ;

                     }
             
                   deplacerperso(&p,p.direction) ; 
                 

                   break ; 

                 case SDLK_DOWN:
                 p.frame.w=66.667 ;
                 p.frame.h=200 ;
                 p.frame.x=333.335 ;
                 p.frame.y=115 ;
                 animerPerso(&p) ;
                 p.direction=2 ;
 
                 if (p.position.x==0)
                 {
                p.direction=1 ;
                p.frame.w=66.667 ;
                p.frame.h=100 ;
                p.frame.x=0 ;
                p.frame.y=0 ;
                  }
              deplacerperso(&p,p.direction) ;
               break ;
         case SDLK_u:
         p.vitesse= p.vitesse+0.1;
          break ; 

          case SDLK_i:
         if(p.vitesse>=1)
         p.vitesse= p.vitesse-0.1;
          break ;
          case SDLK_SPACE:
           p.position.y-=0.5;
            

                   
          
           break ;
            if (g==2)
         {
             case SDLK_d:
                   p2.frame.w=66.667 ;
                     p2.frame.h=100 ;
                     p2.frame.x=0 ;
                     p2.frame.y=0 ;
                     animerPerso(&p2) ;
                     p2.direction=1 ;

                   
 
                     if (p2.position.x==520)
                     { 
                        p2.direction=2 ;
                        p2.frame.w=66.667 ;
                        p2.frame.h=200 ;
                        p2.frame.x=333.335 ;
                        p2.frame.y=115 ;

                     }
             
                   deplacerperso(&p2,p2.direction) ; 
                   break ;
             case SDLK_s :
                p2.frame.w=66.667 ;
                 p2.frame.h=200 ;
                 p2.frame.x=333.335 ;
                 p2.frame.y=115 ;
                 animerPerso(&p2) ;
                 p2.direction=2 ;
 
                 if (p.position.x==0)
                 {
                p2.direction=1 ;
                p2.frame.w=66.667 ;
                p2.frame.h=100 ;
                p2.frame.x=0 ;
                p2.frame.y=0 ;
                  }
              deplacerperso(&p2,p2.direction) ;
            break ;
         }
 

           
      
  break ;

      } 
 
 

}
	
}
SDL_Flip(screen);
return 0  ;
}




