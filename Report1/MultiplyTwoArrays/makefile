#
# makefile
#
#CC=gcc -g
#LIBS= -lstdc++
#
#all: gobhagi
#
multiply_two_arrays: multiply_array.o common.o
	gcc -o multiply_two_arrays multiply_array.o common.o
#
common.o: common.c common.h
	gcc -c common.c -o common.o 
#
multiply_array.o: multiply_array.c
	gcc -c multiply_array.c -o multiply_array.o
#
clean:
	rm -f gobhagi *.o
