CC=gcc -std=c99

all: client server

execute: client.exe server.exe
	

client: client.c
	$(CC) client.c -o client.exe

server: server.c
	$(CC) server.c -lpthread  -o server.exe