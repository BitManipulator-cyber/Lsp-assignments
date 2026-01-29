/* 
 * Author: Aaditya Jagtap
 * Problem Statement: Create a runtime dynamic linked file 
 * using dlfcn library
 * Input : Function call
 * Output: Function called from client program 
 */

/* Header files */
#include <stdio.h>
#include <dlfcn.h>

/* Function pointer */
typedef int (*op_fn)(int, int);

/**
 * call_to_server - dynamically load the functions from
 * server program
 *
 * This function calls add() and sub() function which are
 * not present in client program but they are present in 
 * server program so we are dynamically linking the client
 * program to the server program and the functions are called
 * when we need them only then
 *
 * Return:
 * Though void type but addition and subtraction value is 
 * printed to stdout
 */
void call_to_server()
{
	void *handle;
	char *error;
	op_fn add = NULL, sub = NULL;

	handle = dlopen("./lib/libserver.so", RTLD_LAZY);
	if(!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		return;
	}

	dlerror();

	add = (op_fn) dlsym(handle, "add");
	sub = (op_fn) dlsym(handle, "sub");
	
	error = dlerror();
	if(error)
	{
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
		return;
	}

	printf("Addition = %d\n", add(5, 3));
	printf("Subtraction = %d\n", sub(5,3));

	dlclose(handle);
}

/* Entry point function */
int main()
{
	call_to_server();
	return 0;
}
