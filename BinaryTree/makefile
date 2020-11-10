binaryTreeEx: main.o binaryTree.o
	gcc -o binaryTreeEx main.o binaryTree.o

binaryTree.o: binaryTree.c binaryTree.h
	gcc -c binaryTree.c -o binaryTree.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f binaryTreeEx *.o