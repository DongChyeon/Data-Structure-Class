graph: main.o graph.o node.o heapNode.o minHeap.o vertexSets.o
	g++ -o graph main.o graph.o node.o heapNode.o minHeap.o vertexSets.o

graph.o: graph.cpp graph.h
	g++ -c graph.cpp -o graph.o 

node.o: node.cpp node.h
	g++ -c node.cpp -o node.o
	
heapNode.o: heapNode.cpp heapNode.h
	g++ -c heapNode.cpp -o heapNode.o

minHeap.o: minHeap.cpp minHeap.h
	g++ -c minHeap.cpp -o minHeap.o

vertexSets.o: vertexSets.cpp vertexSets.h
	g++ -c vertexSets.cpp -o vertexSets.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f graph *.o