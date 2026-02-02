/**
 * Author: Aaditya Jagtap
 * Problem Statement: Write a shared library to calculate
 * string length
 */

/* Header files */
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

typedef int (*op_fn)(const char *);

/* Entry point function */
int main(void)
{
	void *handle;
	char *error;
	char  str[1024];

	printf("Enter the string\n");
	fgets(str, sizeof(str), stdin);

	/* Clear the newline character from fgets */
	str[strcspn(str, "\n")] = '\0';

	handle = dlopen("./lib/libstrlen.so", RTLD_LAZY);
	if(handle == NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}

	/* Clear any existing error */
	dlerror();

	op_fn calc_strlen = (op_fn) dlsym(handle, "my_strlen");
	
	error = dlerror();
	if(error)
	{
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
		return 1;
	}

	printf("Length of string is %d\n", calc_strlen(str));

	dlclose(handle);

	return 0;
}
