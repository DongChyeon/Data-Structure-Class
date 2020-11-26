graph: main.o graph.o
	g++ -o graph main.o graph.o

graph.o: graph.cpp graph.h
	g++ -c graph.cpp -o graph.o 

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f graph *.o