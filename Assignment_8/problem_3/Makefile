CC = gcc

app: main.c
	gcc $< -o $@

run: app
	./$<

clean: 
	rm -f app

help:
	@echo '*********************** Help book *****************************'
	@echo '> (make)       to compile the program'
	@echo '> (make run)   to run the executable'
	@echo '> (make clean) to delete the executable and rest unuseful files'
	@echo '****************************************************************'

.PHONY: clean run help 
