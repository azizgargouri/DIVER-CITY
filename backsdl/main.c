#include "function.h"


int main()
{
	SDL_Surface *screen;
	backg back;
	texte texte;
	int T=0;
	Mix_Music *music;
	SDL_Event event;
	int i=1,direction;
	int loop = 1;
	scoreinfo tab[100];
	btn b;
	
	SDL_Surface *button;
	SDL_Rect posButton;
	posButton.x = 100;
	posButton.y = 300;
   posButton.w = 350;
   posButton.h = 186;
   
   button = IMG_Load("button.png");
   
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER| SDL_DOUBLEBUF| SDL_RESIZABLE) == -1)
	{
		printf("Could not initialize SDL:  %s.\n",SDL_GetError());
		return -1;
	}

	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE|SDL_DOUBLEBUF| SDL_RESIZABLE);
	SDL_WM_SetCaption("DATA PIRATES GAME", NULL);
	
	
	initbackg(&back);
	initialiser_audiobref(music);
	TTF_Init();
	//int bck ;
	//bck = 1;
	init_btn(&b);
	while (loop)
	{
		
				
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		
		afficher(back,screen);
		
		//animate_back(&back,screen);
		
		display_btn(b,screen);
		SDL_BlitSurface(button, NULL, screen, &posButton);
		if (T==1){
			bestScore("scores.txt", tab,screen);}
		while(SDL_PollEvent(&event))
		{
			switch(event.type) 
			{
		 		case SDL_QUIT:
		 		loop = 0;
		 		break;
		 		case SDL_KEYDOWN:
		 		switch (event.key.keysym.sym)
		 		{
		 		case SDLK_LEFT:
		 		direction=1;
		 		break; 
		 		case SDLK_DOWN:
		 		direction=2;
		 		break;
		 		case SDLK_RIGHT:
		 		direction=3;
		 		break;
		 		case SDLK_UP:
		 		direction=5;
		 		break;
		 		case SDLK_b :
		 		if(T==1)
		 		{
		 			T=0;
		 		}
		 		else 
		 		{
		 			T=1;
		 		}
		 		case SDL_MOUSEBUTTONDOWN:
            if (event.motion.x >= b.posButton.x && event.motion.x <= b.posButton.x + b.posButton.w && event.motion.y >= b.posButton.y && event.motion.y <= b.posButton.y + b.posButton.h)
            {
                bestScore("scores.txt", tab,screen);
                showBestScore(tab, screen);
            }
            break;
		 		}
		 		scrolling (&back, direction );
		 		break;
		 	}
		 }
		 SDL_Flip(screen);
	}
	
	
	return 0;
}
	
	
