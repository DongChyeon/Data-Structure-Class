matrix_multiplication: main.o matrix.o
	gcc -o matrix_multiplication main.o matrix.o

matrix.o: matrix.c matrix.h
	gcc -c matrix.c -o matrix.o 

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f matrix_multiplication *.o
