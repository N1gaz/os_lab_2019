CC=g++
CFLAGS=-I.

all: exec_demo.exe parallel_min_max.exe

exec_demo.exe: sequential_min_max.exe
	$(CC) -o exec_demo.exe exec_demo.c $(CFLAGS)
	
sequential_min_max.exe : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o sequential_min_max.exe find_min_max.o utils.o sequential_min_max.c $(CFLAGS)

parallel_min_max.exe : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max.exe utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

clean :
	rm utils.o find_min_max.o sequential_min_max.exe parallel_min_max.exe exec_demo.exe
