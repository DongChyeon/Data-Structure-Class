multiplyTwoSparses : multiplyTwoSparses.o common.o
		gcc -o multiplyTwoSparses multiplyTwoSparses.o common.o

common.o : common.c common.h
		gcc -c common.c -o common.o

multiplyTwoSparses.o : multiplyTwoSparses.c
		gcc -c multiplyTwoSparses.c -o multiplyTwoSparses.o