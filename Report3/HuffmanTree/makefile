ArithmeticExp: main.o binaryTree.o queue.o stack.o
	gcc -o ArithmeticExp main.o binaryTree.o queue.o stack.o

binaryTree.o: binaryTree.c binaryTree.h
	gcc -c binaryTree.c -o binaryTree.o

queue.o: queue.c queue.h
	gcc -c queue.c -o queue.o 

stack.o: stack.c stack.h
	gcc -c stack.c -o stack.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f binaryTreeEx *.o