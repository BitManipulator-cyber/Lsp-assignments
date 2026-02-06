CC = gcc
CFLAGS = -Wall -Wextra -O2

lib: mathlib.c
	$(CC) -c $< -o mathlib.o
	ar rcs libmathlib.a mathlib.o

app: mathlib.o main.c
	$(CC) main.c -L. -lmathlib -o app

run: app
	./app

clean:
	rm -f *.o *.a app

