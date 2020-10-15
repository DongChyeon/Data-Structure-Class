stackEx: main.o stack.o
	gcc -o stackEx main.o stack.o

stack.o: stack.c stack.h
	gcc -c stack.c -o stack.o 

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f stackEx *.o