
CC=gcc
OBJECTS_MAIN=main.o node.o
FLAGS= -Wall -g -fPIC
PROGRAMS=frequency

all: $(PROGRAMS)
frequency: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o frequency $(OBJECTS_MAIN) -lm
node.o: node.c node.h
	$(CC) $(FLAGS) -c node.c
main.o: main.c node.h
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so frequency