huffmanTree: main.o binaryTree.o priorityQueue.o
	gcc -o huffmanTree main.o binaryTree.o priorityQueue.o

binaryTree.o: binaryTree.c binaryTree.h
	gcc -c binaryTree.c -o binaryTree.o

priorityQueue.o: priorityQueue.c priorityQueue.h
	gcc -c priorityQueue.c -o priorityQueue.o 

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm huffmanTreeEx *.o