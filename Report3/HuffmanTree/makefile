huffmanTree: main.o huffmanTree.o priorityQueue.o info.o
	gcc -o huffmanTree main.o huffmanTree.o priorityQueue.o info.o

huffmanTree.o: huffmanTree.c huffmanTree.h
	gcc -c huffmanTree.c -o huffmanTree.o

priorityQueue.o: priorityQueue.c priorityQueue.h
	gcc -c priorityQueue.c -o priorityQueue.o 

info.o: info.c info.h
	gcc -c info.c -o info.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm huffmanTreeEx *.o