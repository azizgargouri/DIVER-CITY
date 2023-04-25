prog:function.o main.o options.o play.o
	gcc function.o main.o options.o play.o -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -o prog -g

main.o:main.c
	gcc -c main.c -g

function.o:function.c
	gcc -c function.c -g
	
options.o:options.c
	gcc -c options.c -g
	
play.o:play.c
	gcc -c play.c -g
