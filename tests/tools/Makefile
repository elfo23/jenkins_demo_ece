CFLAGS=-std=c11 -g -Wall
CC=gcc
UNITY=../unity
UTILS=../../source/tools

all: test clean

init:
	mkdir -p build

unity.o: $(UNITY)/unity.c $(UNITY)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY)/unity.c -o build/unity.o

circular_buffer.o: $(UTILS)/circular_buffer.c $(UTILS)/circular_buffer.h
	$(CC) $(CFLAGS) -c $(UTILS)/circular_buffer.c -o build/circular_buffer.o

circular_buffer_tests.o: circular_buffer_tests.c
	$(CC) $(CFLAGS) -I $(UNITY) -c circular_buffer_tests.c -o build/circular_buffer_tests.o

test: init unity.o circular_buffer.o circular_buffer_tests.o
	$(CC) $(CFLAGS) build/unity.o build/circular_buffer.o build/circular_buffer_tests.o -o build/circular_buffer_tests
	build/circular_buffer_tests 

clean:
	rm -rf build/
