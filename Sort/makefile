sort: main.o sort.o minHeap.o
	g++ -o sort main.o sort.o minHeap.o

sort.o: sort.cpp sort.h
	g++ -c sort.cpp -o sort.o

minHeap.o: minHeap.cpp minHeap.h
	g++ -c minHeap.cpp -o minHeap.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f sort *.o