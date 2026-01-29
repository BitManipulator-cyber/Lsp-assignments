/**
 * Author: Aaditya Jagtap
 * Problem Statement: Program that counts the number of 
 * upper case, lower case and digits present in the user
 * input string
 */

/* Header files */
#include <stdio.h>
#include <dlfcn.h>

typedef int (*op_fn)(char *);

/* Entry point function */
int main()
{
	char str[1024];
	void *handle;
	char *error;
	op_fn count;


	printf("Enter the string\n");
	fgets(str, sizeof(str), stdin);

	handle = dlopen("./libcount.so", RTLD_LAZY);
	if(!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
	}

	dlerror();

	count = (op_fn) dlsym(handle, "count_letters_and_digits");

	error = dlerror();
	if(error)
	{
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
	}

	/* Call the function */
	count(str);

	dlclose(handle);

	return 0;
}
