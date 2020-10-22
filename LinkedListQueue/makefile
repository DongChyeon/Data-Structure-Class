queueEx: main.o queue.o
	gcc -o queueEx main.o queue.o

queue.o: queue.c queue.h
	gcc -c queue.c -o queue.o 

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f queueEx *.o