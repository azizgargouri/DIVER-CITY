
#include "function.h"




/*-------------------------------------------------------FONCTIONS INITIALISATION----------------------------------------------------------*/

//Backg
void initbackg(backg *back)
{    
    back->img=IMG_Load("tokyo.png");
    strcpy(back->ImgName,"tokyo.png");
    back->pos1.x=0;
    back->pos1.y=0;
    back->pos1.w=15808;
    back->pos1.h=1080;//512

    back->camera.x=0;
    back->camera.y=0;
    back->camera.w=1920; //1080
    back->camera.h=1920; //512
}


void initialiser_audiobref(Mix_Music*music)
{
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024) == -1)
	{
		printf("%s",SDL_GetError());	
	}
	music = Mix_LoadMUS("dog.mp3");
	Mix_PlayMusic(music,1);
	Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}
void afficher(backg back,SDL_Surface *screen)
{
 SDL_BlitSurface(back.img,&back.camera,screen,&back.pos1); // bliter background fouk screen 
 Mix_Music *music;
 initialiser_audiobref(music);
 
}
void scrolling (backg * back, int direction )
{
	switch(direction) 
	{
		case 1 :
		if(back->camera.x>=10) 
			back->camera.x-=100;
		break;
		case 2 :
		if (back->camera.y<=500)
			back->camera.y+=10;
		break;
		case 3 :
		if (back->camera.x<=12800)
			back->camera.x+=2000;
		break;
		case 5 :
		if(back->camera.y>=10)
			back->camera.y-=2000;
		break;
	}
}
/*void animate_back(backg *back, SDL_Surface *screen)
{
	int i;
	
	if (strcmp(&back->ImgName[1],".")==0	)
   	i = atoi(&back->ImgName[0]);
   else 
   {
		char temp[2];
		strncpy(temp,back->ImgName,2);   	
   	i = atoi(temp);
   }
   	
   if (i > 33)
   	i = 1;
   else
		i = i +1;
		
	/*char ch[30]="";
	sprintf(ch,"%d.tokyo",i);
	back->img=IMG_Load(ch);
	strcpy(back->ImgName,ch);
	
	SDL_Delay(75);
	SDL_BlitSurface(back->img,&back->camera,screen,&back->pos1);

}*/

void initialiser_texte(texte *txte)
{
	
	txte->police = TTF_OpenFont("arial.ttf", 12);
	txte->textColor.r=255;
	txte->textColor.g=255;
	txte->textColor.b=255;
	txte->textpos.x=150;
	txte->textpos.y=150;
}
void bestScore(char *filename, scoreinfo tab[100],SDL_Surface *screen) {
	
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error : can't open %s\n", filename);
        
    }

    // nhez les info ml file w n7othom fe tab 
    int i = 0;
    while (fscanf(fp, "%d %d %s", &tab[i].score, &tab[i].time, tab[i].playername) !=EOF ) {
        i++;
    }

    
    fclose(fp);

    // Trie 
    int n = i;
    for (i = 0; i < n-1; i++) 
    {
        for (int j = i+1; j < n; j++)
        {
            if (tab[j].score > tab[i].score ||(tab[j].score == tab[i].score && tab[j].time < tab[i].time)) 
            {
                scoreinfo tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }

    // display best 3 
    /*SDL_WM_SetCaption("best Scores", NULL);

    char text[50];
    texte texte ;
    initialiser_texte(&texte);
    for (i = 0; i < 3 && i < n; i++) {
        sprintf(text, "%s got %d points in %d seconds.", tab[i].playername, tab[i].score, tab[i].time);
        
        //initialiser_texte(&texte);
        texte.txt=TTF_RenderText_Blended(texte.police,text,texte.textColor);
        SDL_BlitSurface(texte.txt, NULL, screen, &texte.textpos);
        texte.textpos.y+= 50;
        //printf("%s got %d points in %d seconds.", tab[i].playername, tab[i].score, tab[i].time);
        
    }

    

    //SDL_Delay(500);*/

    
}
void showBestScore(scoreinfo t[], SDL_Surface *screen)
{
    /*TTF_Font *font = NULL;
    font = TTF_OpenFont("Retro.ttf", 12);

    SDL_Color textColor = {255, 255, 255};*/

    SDL_Surface *leader;
    leader = IMG_Load("best.png");

    int loop = 1;
    SDL_Event event;

    SDL_FillRect(screen, NULL, 0x000000);
    SDL_BlitSurface(leader, NULL, screen, NULL);
    int y = 170;
    for (int i = 0; i < 3; i++)
    {
        char name[100];
        char info[100];
        texte texte,texte1 ;
        sprintf(name, "player name: %s", t[i].playername);
        sprintf(info, "Score : %d, time : %d", t[i].score, t[i].time);
        
        texte.txt=TTF_RenderText_Blended(texte.police,name,texte.textColor);
        texte1.txt=TTF_RenderText_Blended(texte.police,info,texte.textColor);
        
        SDL_BlitSurface(texte.txt, NULL, screen, &texte.textpos);
        SDL_BlitSurface(texte1.txt, NULL, screen, &texte.textpos+50);
        texte.textpos.y+= 50;
        
        //renderText(screen, font, textColor, name, 320, y);
        //renderText(screen, font, textColor, info, 320, y + 50);
        //y += 150;
    }
    SDL_Flip(screen);
    while (loop)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = 0;
                break;
            }
        }
    }
}
void display_btn(btn b, SDL_Surface *screen)
{
	SDL_BlitSurface(b.button, NULL, screen, &b.posButton);
}
void init_btn(btn *b)
{
	b->button = IMG_Load("button.png");
	b->posButton.x = 100;
	b->posButton.y = 300;
   b->posButton.w = 350;
   b->posButton.h = 186;
}
