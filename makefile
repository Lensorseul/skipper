all:fonction.o 
	gcc fonction.o vendee.c -o vendee
fonction.o:fonction.c
	gcc -c fonction.c