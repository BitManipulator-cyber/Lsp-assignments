/**
 * Author: Aaditya Jagtap
 * Problem Statement: Write a program that is linked with 2 seperate
 * shared libraries
 *
 * Proposed Solution:
 * 	Client -> libaddition.so    -> addition()
 * 	Client -> libsubtraction.so -> subtraction()
 */

/* Header files */
#include <stdio.h>
#include <dlfcn.h>

typedef int (*op_fn)(int, int);

/* Entry point function */
int main()
{
	void *handle1, *handle2;
	char *error;
	op_fn add, sub;
	int no1, no2;

	printf("Enter no1:\n");
	scanf("%d", &no1);

	printf("Enter no2:\n");
	scanf("%d", &no2);

	handle1 = dlopen("./lib/libaddition.so", RTLD_LAZY);

	if(handle1 == NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}

	/* Clear any existing errors */
	dlerror();

	add = (op_fn) dlsym(handle1, "addition");
	error = dlerror();
	if(error)
	{
		fprintf(stderr, "%s\n", error);
		dlclose(handle1);
		return 1;
	}

	dlerror();

	handle2 = dlopen("./lib/libsubtraction.so", RTLD_LAZY);
	error = dlerror();
	if(handle2 == NULL)
	{
		fprintf(stderr, "%s\n", error);
		return 1;
	}

	dlerror();

	sub = (op_fn) dlsym(handle2, "subtraction");
	error = dlerror();
	if(error)
	{
		fprintf(stderr, "%s\n", error);
		dlclose(handle2);
		return 1;
	}

	printf("Addition    = %d\n", add(no1, no2));
	printf("Subtraction = %d\n", sub(no1, no2));

	dlclose(handle1);
	dlclose(handle2);

	return 0;
}
