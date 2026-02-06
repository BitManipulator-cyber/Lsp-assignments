CC = gcc
CFLAGS = -Wall -Wextra -O2

app: main.o helper.o
	$(CC) main.o helper.o -o app

main.o: main.c helper.h
	$(CC) $(CFLAGS) -c main.c

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c

clean:
	rm -f *.o app

.PHONY: clean
