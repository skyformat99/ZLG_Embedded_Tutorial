# Makefile for hello
EXE = bugging
OBJ = bugging.o
SRC = bugging.c

#CC = gcc
CC = /home/ctools/arm-2011.03/bin/arm-none-linux-gnueabi-gcc
CFLAGS = -g
LDFLAGS = 

EXE:$(OBJ)
	$(CC) $(LDFLAGS) -o $(EXE) $^

OBJ:$(SRC)
	$(CC) $(CFLAGS) -o $(OBJ) -c $^ #hello

.PHONY:clean
clean:
	$(RM) $(OBJ) $(EXE)



