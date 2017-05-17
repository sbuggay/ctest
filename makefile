CC=gcc
CFLAGS=-c -Wall

all: ctest

ctest: ctest.o example.o runner.o
	$(CC) ctest.o runner.o example.o -o ctest

ctest.o: ctest.c
	$(CC) $(CFLAGS) ctest.c

runner.o: runner.c
	$(CC) $(CFLAGS) runner.c

example.o: example.c
	$(CC) $(CFLAGS) example.c

clean:
	rm *.o ctest