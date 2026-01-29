/*
   Author : Aaditya Jagtap
   Problem Statement : Write a program to demonstrate dynamic
   library search path resolution in Linux
  
   Proposed solution:
   
   Linking type - Normal Dynamic Linking(implicit)
   Folder structure
     .
     ├── lib            - folder that contains the .so file
     │   ├── calc.h     - header file
     │   ├── sub.c      - contains the logic for sub()
     │   ├─  sub.o      - object file of sub.c file
     │   └── sub_dll.so - the .so file
     └── main.c         - the program which will call the .so symbols
 */

/* Header files */
#include <stdio.h>
#include "./lib/calc.h"

int main()
{
	printf("Subtraction = %d\n", sub(10,4));
	return 0;
}

/*
   Compilation steps:

   	(1) Link the main.c implicitely with the .so file present in ./lib

		>> gcc main.c -L./lib -lcalc -o main

	(2) Let the ld-linux.so know where to find the .so file for main

		>> export LD_LIBRARY_PATH=./lib

	(3) Run the main

		>> ./main
 */

