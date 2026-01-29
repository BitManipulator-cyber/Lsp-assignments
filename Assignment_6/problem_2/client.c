/* 
 * Author: Aaditya Jagtap
 * Problem Statement: Create a runtime dynamic linked file 
 * using dlfcn library and explain each function
 * Input : Function call
 * Output: Function called from client program 
 */

/* Header files */
#include <stdio.h>
#include <dlfcn.h>

/* Function pointer */
typedef int (*op_fn)(int, int);

/* Entry point function */
int main()
{
	void *handle;
	op_fn add = NULL, sub = NULL;

	/**
	 * dlopen() - loads the dynamic shared object
	 *
	 * @path : specify the path of .so file
	 * @flags: determines when to load the dll
	 *
	 * RTLD_LAZY -  Load the function when needed at runtime
	 * RTLD_NOW  -  Load the function immediately at runtime
	 *
	 * If the path is set to NULL, then the returned handle is 
	 * for the main program i.e, now we can access the function
	 * from the same program from where we are calling the function
	 *
	 * Return:
	 * A non-NULL handle for the loaded object
	 */
	 handle = dlopen("./libserver.so", RTLD_LAZY);
	 if (!handle)
	 {
		 fprintf(stderr, "%s\n", dlerror());
		 return;
	 }

	 /**
	  * dlerror - obtain error diagnostic for functions in the 
	  * dlopen API
	  *
	  * The dlerror() function returns human-readble, null
	  * terminated string describing the most recent error 
	  * that occured from a call to one of the functions
	  * in the dlopen API since the last call to dlerror()
	  */
	 dlerror();
	 
	 /**
	  * dlsym() - obtain the address of a symbol in a shared
	  * object or executable
	  *
	  * @handle - contains the dynamic loaded shared object
	  * @symbol - every variable, function in .so file is treated 
	  * 	      as a symbol
	  * 
	  * The function dlsym() takes a "handle" of a dynamic 
	  * shared object returned by dlopen() along with a null
	  * terminated symbol name, and returns the address where
	  * that symbol is loaded into memory
	  *
	  * Return:
	  * On success, returns these function return the address 
	  * associated with symbol
	  */
	 add = (op_fn) dlsym(handle, "add");
	 sub = (op_fn) dlsym(handle, "sub");

	 error = dlerror();

	 if (error)
	 {
		 fprintf(stderr, "%s\n", error)
		 dlclose(handle);
		 return;
	 }

	 printf("Addition = %d\n", add(5, 3));
	 printf("Subtraction = %d\n", sub(5,3));

	 /**
	  * dlclose() - closes a symbol table handle
	  *
	  * @handle: takes handle to close
	  *
	  * The dlclose() function shall inform the system
	  * that the symbol table handle specified by the 
	  * handle is no longer needed by the application
	  *
	  * Return:
	  * On success, zero is returned
	  */
	 dlclose(handle);
	 return 0;
}
