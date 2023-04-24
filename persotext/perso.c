 #include "perso.h"
void initPerso(Personne *p)
{  
   (*p).image=IMG_Load("jj.png");  

    p->position.x=0;
    p->position.y=160; //160

    p->frame.w=66.667; //66.667
    p->frame.h=100;//100
    p->frame.x=0;
    p->frame.y=0;

    p->curframe=1;
    p->vitesse=1;
    p->direction=1;
  
   
    p->x = 4;
    p->grav = 0.5;
    p->saut = -6.5;
    p->y = p->saut;
   
}
void initPerso2(Personne *p2)
{
     (*p2).image=IMG_Load("jump.png");  

    p2->position.x=5;
    p2->position.y=160;

    p2->frame.w=66.667;
    p2->frame.h=100;
    p2->frame.x=0;
    p2->frame.y=0;

    p2->curframe=1;
    p2->vitesse=1;
    p2->direction=1;
  
   
    p2->x = 4;
    p2->grav = 0.5;
    p2->saut = -6.5;
    p2->y = p2->saut;

}

void afficherPerso (Personne p,SDL_Surface *screen)
{
    SDL_BlitSurface(p.image,&(p.frame),screen,&(p.position)); 
}

void deplacerperso(Personne *p,int dt) 
{
 if (dt==1)
    p->position.x=p->position.x+p->vitesse;
 if (dt==2)
     p->position.x=p->position.x-p->vitesse;

}

void animerPerso(Personne *p)
{
         
               p->curframe++ ;
     if(p->curframe>=6)
	{
		p->curframe=0;
	}
		p->frame.x=p->curframe * p->frame.w;  
}
void saut(Personne *p)
{ 

  	if(p->position.y<160)
         {

   	p->position.x += p->x;
   	p->position.y+= p->y;
   	p->y += p->grav;
   } //eq parabole 
  	if (p->position.y> 160)
    	p->y = p->saut;
       


}
