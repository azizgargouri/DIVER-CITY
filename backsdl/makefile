prog:function.o main.o
	gcc function.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o:main.c function.h
	gcc -c main.c -I. -g
function.o:function.c function.h
	gcc -c function.c -I. -g
