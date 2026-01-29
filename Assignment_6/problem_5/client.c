/**
 * Author: Aaditya Jagtap
 * Problem Statment: Diffrence between RTLD_LAZY
 * and RTLD_NOW flags at run time
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
	op_fn add;

	/*------- Using RTLD_LAZY flag ---------*/
	handle = dlopen("./libserver.so", RTLD_LAZY);

	if(!handle){
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}

	dlerror();

	add = (op_fn) dlsym(handle, "add");
	error = dlerror();
	
	if(error)
	{
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
		return 1;
	}

	printf("Add using RTLD_LAZY: %d\n", add(5,3));
	dlclose(handle);

	
	/*------- Using RTLD_NOW flag ---------*/
	handle = dlopen("./libserver.so", RTLD_NOW);

	if(!handle){
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}

	dlerror();

	add = (op_fn) dlsym(handle, "add");
	error = dlerror();
	
	if(error)
	{
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
		return 1;
	}

	printf("Add using RTLD_LAZY: %d\n", add(5,3));
	dlclose(handle);

	/**
	 * Explanation of the flags:
	 *
	 * RTLD_LAZY - Performs lazy binding. Resolve 
	 * symbols only as the code that referenced them
	 * is executed. If the symbol is never referenced, 
	 * then it is never resolved.
	 *
	 * RTLD_NOW - If the value is specified, or the
	 * enviroment variable LD_BIND_NOW is set to non
	 * empty string, all undefined symbols in the 
	 * shared object are resolved before dlopen()
	 * returns.
	 */

	return 0;
}
