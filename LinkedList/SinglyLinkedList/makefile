linkedListEx: main.o linkedList.o
	gcc -o linkedListEx main.o linkedList.o

linkedList.o: linkedList.c linkedList.h
	gcc -c linkedList.c -o linkedList.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f linkedListEx *.o