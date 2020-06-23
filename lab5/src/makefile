CC=gcc

all: mutex parallel_factorial
	

mutex: mutex.c
	$(CC) mutex.c -lpthread -o mutex.exe

parallel_factorial: parallel_factorial.c
	$(CC) -std=c99 parallel_factorial.c -o parallel_factorial.exe

clear:
	rm mutex.exe parallel_factorial.exe