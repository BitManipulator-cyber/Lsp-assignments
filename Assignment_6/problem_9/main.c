/**
 * Author : Aaditya Jagtap
 * Problem Statement : Store the multiple dynamically loaded
 * functions in an array of function pointers. And invoke them
 * using array also display function address along with results
 */

/* Header files */
#include <stdio.h>
#include <dlfcn.h>

typedef int (*op_fn)(int, int);

/* Entry point function */
int main()
{
	void *handle;
	char *error;
	op_fn math_fn[3];

	handle = dlopen("./libmath.so", RTLD_LAZY);
	if(!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}

	/* Clear any existing errors */
	dlerror();

	/* Load the symbols */
	math_fn[0] = (op_fn) dlsym(handle, "add");
	math_fn[1] = (op_fn) dlsym(handle, "mul");
	math_fn[2] = (op_fn) dlsym(handle, "div");

	error = dlerror();
	if(error)
	{
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
		return 1;
	}

	int a = 10, b = 5;
	const char *names[] = {"add", "mul", "div"};

	for(int i = 0; i < 3; i++)
	{
		int result = math_fn[i](a, b);
		printf("Function name: %s\n", names[i]);
		printf("Address: %p\n", (void *)math_fn[i]);
		printf("Result: %d\n", result);
		printf("\n");
	}

	dlclose(handle);

	return 0;
}
