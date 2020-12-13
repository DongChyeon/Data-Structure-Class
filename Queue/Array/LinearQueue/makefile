queue: main.o
	g++ -o queue main.o

main.o: main.cpp queue.h
	g++ -c main.cpp -o main.o

clean:
	rm -f queue *.o