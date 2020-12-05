sort: main.o sort.o
	g++ -o sort main.o sort.o

sort.o: sort.cpp sort.h
	g++ -c sort.cpp -o sort.o 

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f sort *.o