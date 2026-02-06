CC = gcc

# app: main.c
# <TAB> $(CC) main.c -o app

app: main.c
	$(CC) $^ -o $@

run: app
	./app

clean: app
	rm ./app

.PHONY: clean

# Automatic variables
# $< : first dependancy
# $@ : target name
# $^ : all dependancies
