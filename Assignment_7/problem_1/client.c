/*
 * Author: Aaditya Jagtap
 * Problem Statement: Create a 2 level chain of dynamically linked libraries
 * Program Flow:
 * 	Client -> libperfect.so -> libhelper.so
 *
 * The libraries contains:
 * 	(1) libperfect.so:
 * 		- The is_perfect() function which checks if the number is perfect
 * 		  with the help of sum_of_factors() function which is present in
 * 		  libhelper.so
 * 		- This library is dynamically linked to libhelper.so
 * 	(2) libhelper.so:
 * 		- The sum_of_factors() checks if the factors make up perfect sum
 * 		  with the number
 * 		- This library produces the sum and gives it to perfect.c program
 * Folder structure:
 *   .
 *   ├── client.c
 *   └── lib
 *        ├── helper.c
 *        ├── helper.h
 *        ├── helper.o
 *        ├── libhelper.so
 *        ├── libperfect.so
 *        ├── perfect.c
 *        ├── perfect.h
 *        └── perfect.o
 */

/* Header files */
#include <stdio.h>
#include <dlfcn.h>

typedef int (*op_fn)(int);

/* Entry point function */
int main()
{
	void *handle;
	char *error;
	int  no;

	printf("Enter the number to check if perfect:\n");
	scanf("%d", &no);

	handle = dlopen("./lib/libperfect.so", RTLD_LAZY);
	if(handle == NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}

	/* Clear any existing errors */
	dlerror();

	op_fn check_perfect = (op_fn) dlsym(handle, "is_perfect");
	error = dlerror();
	if(error)
	{
		fprintf(stderr, "%s\n", error);
		dlclose(handle);
		return 1;
	}

	check_perfect(no);

	dlclose(handle);

	return 0;
}
