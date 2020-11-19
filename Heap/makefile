heapEx: main.o heap.o
	gcc -o heapEx main.o heap.o

heap.o: heap.c heap.h
	gcc -c heap.c -o heap.o 

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f heapEx *.o