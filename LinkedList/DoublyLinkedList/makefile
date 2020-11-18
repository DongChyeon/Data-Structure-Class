doublyLinkedListEx: main.o doublyLinkedList.o
	gcc -o doublyLinkedListEx main.o doublyLinkedList.o

doublyLinkedList.o: doublyLinkedList.c doublyLinkedList.h
	gcc -c doublyLinkedList.c -o doublyLinkedList.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f doublyLinkedListEx *.o