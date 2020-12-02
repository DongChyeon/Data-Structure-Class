graph: main.o graph.o node.o path.o vertexSets.o
	g++ -o graph main.o graph.o node.o path.o vertexSets.o

graph.o: graph.cpp graph.h
	g++ -c graph.cpp -o graph.o 

node.o: node.cpp node.h
	g++ -c node.cpp -o node.o
	
path.o: path.cpp path.h
	g++ -c path.cpp -o path.o

vertexSets.o: vertexSets.cpp vertexSets.h
	g++ -c vertexSets.cpp -o vertexSets.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f graph *.o