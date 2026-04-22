CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
AR = ar
ARFLAGS = rcs

all: libmy_vector.a

libmy_vector.a: my_vector.o
	$(AR) $(ARFLAGS) $@ $^

my_vector.o: my_vector.c my_vector.h
	$(CC) $(CFLAGS) -c my_vector.c -o my_vector.o

test: libmy_vector.a
	$(CC) $(CFLAGS) test.c -L. -lmy_vector -o test
	./test

example: libmy_vector.a
	$(CC) $(CFLAGS) example.c -L. -lmy_vector -o example

install: libmy_vector.a
	sudo cp my_vector.h /usr/local/include/
	sudo cp libmy_vector.a /usr/local/lib/

clean:
	rm -f *.o *.a test example

.PHONY: all test clean install