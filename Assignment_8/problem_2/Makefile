CC = gcc
CFLAGS = -Wall -Wextra -O2

app: main.c
	$(CC) $< -o $@

run: app
	./app

clean:
	rm -f ./app
