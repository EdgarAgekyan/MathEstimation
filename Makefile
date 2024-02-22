SHELL := /bin/sh
CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: mathlib-test

mathlib-test: e.c newton.c madhava.c euler.c bbp.c viete.c mathlib-test.c
	$(CC) -o mathlib-test e.c madhava.c newton.c euler.c bbp.c viete.c mathlib-test.c -lm

mathlib-test.o: *.c
	$(CC) $(CFLAGS) -c *.c

clean:
	rm -f mathlib-test *.o

format:
	clang-format -i -style=file *.[ch]

