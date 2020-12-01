polynomial: main.o polynomial.o
	gcc -o polynomial main.o polynomial.o

polynomial.o: polynomial.c polynomial.h
	gcc -c polynomial.c -o polynomial.o 

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f polynomialEx *.o