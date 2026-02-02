/**
 * Author: Aaditya Jagtap
 * Problem Statement: Dynamically link to a shared library which
 * displays a string on standard output
 *
 * Program Flow:
 * 	Client -> libdisplay.so -> display()
 */

/* Header files */
#include <stdio.h>
#include <dlfcn.h>

typedef void (*op_fn)(char *);

int main()
{
	void *handle;
	char *err;
	char str[1024];

	printf("Enter the string\n");
	fgets(str, sizeof(str), stdin);

	handle = dlopen("./lib/libdisplay.so", RTLD_NOW);
	if(handle == NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}

	dlerror();

	op_fn display_str = (op_fn) dlsym(handle, "display");
	err = dlerror();
	if(err)
	{
		fprintf(stderr, "%s\n", err);
		dlclose(handle);
		return 1;
	}

	display_str(str);

	return 0;
}
