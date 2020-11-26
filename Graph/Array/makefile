graph: main.o graph.o
	gcc -o graph main.o graph.o

graph.o: graph.cpp graph.h
	gcc -c graph.cpp -o graph.o 

main.o: main.cpp
	gcc -c main.cpp -o main.o

clean:
	rm -f graph *.o