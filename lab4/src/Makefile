CC=g++

all: parallel_sum
	
parallel_sum: parallel_sum.c sum.o utils.o
	$(CC) parallel_sum.c sum.o utils.o -o parallel_sum.exe

sum.o: sum.c sum.h
	$(CC) -c sum.c -o sum.o

utils.o: utils.h utils.c
	$(CC) -c utils.c -o utils.o

clear:
	rm parallel_sum.exe utils.o sum.o