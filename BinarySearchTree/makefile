binarySearchTree: main.o binarySearchTree.o binaryNode.o
	g++ -o binarySearchTree main.o binarySearchTree.o binaryNode.o

binarySearchTree.o: binarySearchTree.cpp binarySearchTree.h
	g++ -c binarySearchTree.cpp -o binarySearchTree.o

binaryNode.o: binaryNode.cpp binaryNode.h
	g++ -c binaryNode.cpp -o binarynode.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f BinarSearchTree *.o