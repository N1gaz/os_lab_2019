CC=g++
CFLAGS=-I.

all: parallel_min_max Shawn

parallel_min_max: find_min_max
	$(CC) parallel_min_max.c find_min_max.o utils.o -o parallel_min_max.exe

find_min_max: utils
	$(CC) -c find_min_max.c -o find_min_max.o

utils:
	$(CC) -c utils.c -o utils.o

Shawn:
	$(CC) Shawn.c -o Shawn.exe

clear:
	rm parallel_min_max.exe find_min_max.o utils.o Shawn.exe