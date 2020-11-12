binaryTreeEx: main.o binaryTree.o queue.o
	gcc -o binaryTreeEx main.o binaryTree.o queue.o

binaryTree.o: binaryTree.c binaryTree.h
	gcc -c binaryTree.c -o binaryTree.o

queue.o: queue.c queue.h
	gcc -c queue.c -o queue.o 

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f binaryTreeEx *.o