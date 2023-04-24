#include "enigme.h"

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
 
void initialiser_imagequestion(image boutoun[],image winorlose[],image longbouton[])//
{
 int i;
longbouton[0].img=IMG_Load("Longbuttons.png"); //
longbouton[0].pos.x=-250;                       //
longbouton[0].pos.y=-230;                        //

winorlose[0].img=IMG_Load("Win.png");
winorlose[1].img=IMG_Load("Lose.png");

winorlose[0].pos.x=590; 
winorlose[0].pos.y=20; //100
winorlose[1].pos.x=515;
winorlose[1].pos.y=100;
   

for(i=0;i<3;i++)

    boutoun[i].img=IMG_Load("Buttons.png");

    boutoun[0].pos.x=200;
    boutoun[0].pos.y=400;
   
    boutoun[1].pos.x=550;
    boutoun[1].pos.y=400;
    
    boutoun[2].pos.x=900;
    boutoun[2].pos.y=400;


}

void generer(enigme *e ,char *nomfichier)

{
	int nbquestion=0;

    srand(time(0));
    e->choix_question=(rand() % (4)) +1;

    SDL_Color couleurNoire= {0,0,0};
    

     SDL_Color couleuryellow= {150,250,90};
    TTF_Font *police;


    police = TTF_OpenFont("8-bit.ttf", 25);

    FILE *F;
    
    F=fopen(nomfichier, "r");
    
    if(F!=NULL)
	    {
while((fscanf(F,"%s , %s , %s , %s  %d \n",e->question,e->reponseA,e->reponseB,e->reponseC,&(e->correctAnswer))!=EOF) && (nbquestion!=e->choix_question)) 
		{
		    nbquestion++;
		}
	    }
    else 
	    printf("erreur lors de l'execution du fichier\n");
	    fclose(F);


 printf("%s \n %d \n",e->question,e->correctAnswer);

    e->quest= TTF_RenderText_Solid(police,e->question,couleuryellow);
    e->PosQuestion.x=200;
    e->PosQuestion.y=250;

    e->reponses[0]= TTF_RenderText_Blended(police,e->reponseA,couleurNoire);
    e->PosReponse[0].x=235;
    e->PosReponse[0].y=435;
    
    e->reponses[1]= TTF_RenderText_Blended(police,e->reponseB,couleurNoire);
    
    e->PosReponse[1].x=570;
    e->PosReponse[1].y=435;

    e->reponses[2]= TTF_RenderText_Blended(police,e->reponseC,couleurNoire);
    e->PosReponse[2].x=925;
    e->PosReponse[2].y=435;

}


void afficherEnigme(enigme *e, SDL_Surface *screen)

{

    SDL_BlitSurface(e->quest,NULL,screen,&(e->PosQuestion));
    SDL_BlitSurface(e->reponses[0],NULL,screen,&(e->PosReponse[0]));
    SDL_BlitSurface(e->reponses[1],NULL,screen,&(e->PosReponse[1]));
    SDL_BlitSurface(e->reponses[2],NULL,screen,&(e->PosReponse[2]));

}

void afficherbutton(image a, SDL_Surface *screen)
			
{
    SDL_BlitSurface(a.img,NULL,screen,&a.pos);
}

void menigme (enigme *e)
{
SDL_Surface *horloge[10];
SDL_Rect p;


    time_t begin,end;
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    begin=clock();
    SDL_Surface *screen;
    SDL_Surface *back=NULL,*b;
    Mix_Music *music;
    Mix_Chunk *mus;
    SDL_Rect pos,bpos;

 

    int continuer=1,continuer1=1,rep=0,temps=0;


    SDL_Event event;

    screen=SDL_SetVideoMode(1380,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF  );
    initialiser_audio(music);
    if(!screen)
    {
        printf("Error Screen %s\n", SDL_GetError());
    }
    back= IMG_Load("EnigmeBackground.png");
    pos.x=0;
    pos.y=0;
    p.x=680;
    p.y=320;
    b=IMG_Load("RightButtons.png");
    bpos.x=200;
    bpos.y=405;  


   
   image boutoun[3],winorlose[2],longbouton[1]; //
   inithorloge(horloge);
   initialiser_imagequestion(boutoun,winorlose,longbouton); //
    generer(e,"enigme.txt");
    while(continuer1)
    {
    while(continuer)
    {
    end=clock();
        temps=(end-begin)/CLOCKS_PER_SEC;
        if(temps==9)
        continuer=0;
        SDL_BlitSurface(back,NULL,screen,&pos);
        SDL_BlitSurface(horloge[temps],NULL,screen,&p);
        afficherbutton(boutoun[0], screen);
        afficherbutton(boutoun[1], screen);
        afficherbutton(boutoun[2], screen);
        //afficherbutton(longbouton[0], screen); //
        afficherEnigme(e,screen);
        SDL_Flip(screen);
        
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
        {
            continuer=0;
        }
        break;

        case SDL_KEYDOWN:
        {
         
            switch(event.key.keysym.sym)
            {
            
            case SDLK_a:            
                rep=1;
                break;
                
            case SDLK_b:
                rep=2;
                break;
                
            case SDLK_c:
                rep=3;
                break;

            }
        }
        break;
        
        case SDL_MOUSEMOTION:
        
        rep=0;

            if (event.motion.x>220 && event.motion.y>400 && event.motion.x<520 && event.motion.y<550 )
            {
            rep=1;
            }
            if (event.motion.x>570 && event.motion.y>400 && event.motion.x<870 && event.motion.y<550)
            {
            rep=2;
            }
            if (event.motion.x>920 && event.motion.y>400 && event.motion.x<1220 && event.motion.y<550 )
            {                
            rep=3;
            }
        break; 
         
        case SDL_MOUSEBUTTONDOWN:
             
            if (event.button.button==SDL_BUTTON_LEFT)
            {
                if (rep!=0)
		continuer=0;
            }
        break;
        }
     }
     
     SDL_PollEvent(&event);
    if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                continuer1= 0;
            }
         
if(rep==e->correctAnswer)
{
 afficherbutton(winorlose[0], screen);
 //Score ++
//Time ++
}
      
else 
{
 SDL_BlitSurface(b,NULL,screen,&bpos);
 afficherbutton(winorlose[1], screen);
 //Score --
//Time --
}
 SDL_Flip(screen);
     }
}     
void inithorloge(SDL_Surface *horloge[])
{

horloge[0] =IMG_Load("horloge/1horloge.gif");
horloge[1] =IMG_Load("horloge/2horloge.gif");
horloge[2] =IMG_Load("horloge/3horloge.gif");
horloge[3] =IMG_Load("horloge/4horloge.gif");
horloge[4] =IMG_Load("horloge/5horloge.gif");
horloge[5] =IMG_Load("horloge/6horloge.gif");
horloge[6] =IMG_Load("horloge/7horloge.gif");
horloge[7] =IMG_Load("horloge/8horloge.gif");
horloge[8] =IMG_Load("horloge/9horloge.gif");
horloge[9] =IMG_Load("horloge/10horloge.gif");


}



