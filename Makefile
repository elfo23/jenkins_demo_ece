CFLAGS=-std=c99 -g -Wall -I include
CC=gcc
UNITY=./unity

all: init test

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

stack.o: include/stack.h src/stack.c
	$(CC) $(CFLAGS) -c src/stack.c -o build/stack.o

stack_test.o: test/stack_test.c
	$(CC) $(CFLAGS) -I $(UNITY) -c test/stack_test.c -o build/stack_test.o

test: init unity.o stack.o stack_test.o
	$(CC) $(CFLAGS) build/unity.o build/stack.o build/stack_test.o -o build/stack_test

clean:
	rm -rf build/
