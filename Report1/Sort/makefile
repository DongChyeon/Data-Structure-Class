sorting: main.o sort.o
	gcc -o sorting main.o sort.o

sort.o: sort.c sort.h
	gcc -c sort.c -o sort.o 

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f sorting *.o