minHeap: main.o minHeap.o
	g++ -o minHeap main.o minHeap.o

minHeap.o: minHeap.cpp minHeap.h
	g++ -c minHeap.cpp -o minHeap.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f minHeap *.o