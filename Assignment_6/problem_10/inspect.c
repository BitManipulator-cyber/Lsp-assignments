/*
   Author: Aaditya Jagtap
   Problem Statement: Design and implement a mini dynamic 
   library inspection tool and if the symbol is found then 
   print it's address else display the respective error message
 */

/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*op_fn)(int, int);

int main(int argc, char *argv[])
{
	/**
	 * argv[1] - path to the dynamic library
	 * argv[2] - the symbol
	 */
	if((argv[1] == NULL) || (argv[2] == NULL))
	{
		printf("Insufficient command line args\n");
		exit(0);
	}

	void *handle;
	char *error;
	
	handle = dlopen(argv[1], RTLD_LAZY);
	if(handle == NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}

	dlerror();

	if(((op_fn) dlsym(handle, argv[2])) == NULL)
	{
		error = dlerror();
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
		return 1;
	}
	else
	{
		printf("Symbol %s found\n", argv[2]);
		printf("Address of symbol: %p\n", (void *)argv[2]);
	}

	dlclose(handle);

	return 0;
}

/*
  Compilation steps:
  	
  	(1) Compile the program normally
		> gcc inspect.c -o inspect -ldl

	(2) Run the executable with the command line arguments
		```
		Case 1: The symbol exists
		Input : ./inspect ./libfunc.so add
		Output: 
			Symbol add found
			Address of symbol: 0x7ffc8f67b0b6
	
		--------------------------------------------
		Case 2: The symbol does not exists
		Input: ./inspect ./libfunc.so abcd
		Output: 
			./libfunc.so: undefined symbol: abcd
		```
	This program handles all the edge cases for the command line
	arguments
 */
