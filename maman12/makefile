magic: magic.o utils.o
	gcc -g -ansi -Wall -pedantic magic.o utils.o -o magic
magic.o: magic.c magic.h
	gcc -c -ansi -Wall magic.c -o magic.o
utils.o: utils.c magic.h
	gcc -c -g -ansi -Wall utils.c -o utils.o
clean:
	rm -f *.o