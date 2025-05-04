mainmat: mymat.o parser.o mainmat.o
	gcc -g -ansi -Wall -pedantic mymat.o parser.o mainmat.o -lm -o mainmat

mymat.o: mymat.c mymat.h parser.h
	gcc -c -g -ansi -Wall mymat.c -o mymat.o

parser.o: parser.c parser.h
	gcc -c -g -ansi -Wall parser.c -o parser.o

mainmat.o: mainmat.c mymat.h parser.h
	gcc -c -g -ansi -Wall mainmat.c -o mainmat.o