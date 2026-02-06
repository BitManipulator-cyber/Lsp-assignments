CC = gcc

so: mathlib.c
	$(CC) -fPIC -shared $< -o libmathlib.so

app: main.c libmathlib.so
	$(CC) $< -L. -lmathlib -o $@

run: app
	LD_LIBRARY_PATH=. ./app

clean:
	rm -f *.so app

.PHONY: clean

