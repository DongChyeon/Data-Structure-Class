maxHeap: main.o maxHeap.o
	g++ -o maxHeap main.o maxHeap.o

maxHeap.o: maxHeap.cpp maxHeap.h
	g++ -c maxHeap.cpp -o maxHeap.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f maxHeap *.o