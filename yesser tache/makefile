prog: temps.o minimap.o main.o 
	gcc  temps.o minimap.o score.o main.o save.o -o prog -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
minimap.o:minimap.c
	gcc -c minimap.c -g
perso.o:temps.c
	gcc -c temps.c -g
score.o:score.c
	gcc -c score.c -g
main.o:main.c
	gcc -c main.c -g
save.o:main.c
	gcc -c save.c -g
