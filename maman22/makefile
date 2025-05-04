mainmat: mymat.o mainmat.o
	gcc -g -ansi -Wall -pedantic mymat.o mainmat.o -lm -o mainmat
mymat.o: mymat.c mymat.h
	gcc -c -g -ansi -Wall mymat.c -o mymat.o
mainmat.o: mainmat.c mymat.h
	gcc -c -g -ansi -Wall mainmat.c -o mainmat.o
 