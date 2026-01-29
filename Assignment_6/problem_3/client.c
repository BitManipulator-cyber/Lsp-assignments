/**
 * Author: Aaditya Jagtap
 * Problem statement: Use functions from the server
 * program and the function call should be decided by 
 * the user
 */

/* Header file */
#include <stdio.h>
#include <dlfcn.h>

typedef int (*op_fn)(int, int);

/**
 * call_add - calls the addition function from the
 * server program
 *
 * @num1: the first number for operation
 * @num2: the second number for operation
 *
 * This function calls the add function from the
 * server program and it loads the library dynamically
 * at runtime with help of dlsym() functions. And handles
 * the errors if the symbols are not found at the runtime
 *
 * Return:
 * Addition of numbers
 */
void call_add(int num1, int num2)
{
    void *handle;
    char *error;
    op_fn add;

    handle = dlopen("./lib/libserver.so", RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        return;
    }

    dlerror();  /* clear old error */

    add = (op_fn)dlsym(handle, "add");

    error = dlerror();
    if (error)
    {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return;
    }

    printf("Addition = %d\n", add(num1, num2));
    dlclose(handle);
}

/**
 * call_sub - calls the subtraction function from the
 * server program
 *
 * @num1: the first number for operation
 * @num2: the second number for operation
 *
 * This function calls the sub function from the
 * server program and it loads the library dynamically
 * at runtime with help of dlsym() functions. And handles
 * the errors if the symbols are not found at the runtime
 *
 * Return:
 * Subtraction of numbers
 */
void call_sub(int num1, int num2)
{
    void *handle;
    op_fn sub;
    char *error;

    handle = dlopen("./lib/libserver.so", RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        return;
    }

    /* Clear any existing error */
    dlerror();

    sub = (op_fn) dlsym(handle, "sub");

    error = dlerror();
    if (error != NULL)
    {
        fprintf(stderr, "dlsym error: %s\n", error);
        dlclose(handle);
        return;
    }

    printf("Subtraction = %d\n", sub(num1, num2));

    dlclose(handle);
}

/**
 * call_mul - calls the multiplication function from the
 * server program
 *
 * @num1: the first number for operation
 * @num2: the second number for operation
 *
 * This function calls the mul function from the
 * server program and it loads the library dynamically
 * at runtime with help of dlsym() functions. And handles
 * the errors if the symbols are not found at the runtime
 *
 * Return:
 * Multiplication of numbers
 */
void call_mul(int num1, int num2)
{
    void *handle;
    op_fn mul;
    char *error;

    handle = dlopen("./lib/libserver.so", RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        return;
    }

    dlerror();

    mul = (op_fn)dlsym(handle, "mul");

    error = dlerror();
    if (error)
    {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return;
    }

    printf("Multiplication = %d\n", mul(num1, num2));
    dlclose(handle);
}

/**
 * call_div - calls the division function from the
 * server program
 *
 * @num1: the first number for operation
 * @num2: the second number for operation
 *
 * This function calls the div function from the
 * server program and it loads the library dynamically
 * at runtime with help of dlsym() functions. And handles
 * the errors if the symbols are not found at the runtime
 *
 * Return:
 * Division of numbers
 */
void call_div(int num1, int num2)
{
    void *handle;
    op_fn div_fn;
    char *error;

    if (num2 == 0)
    {
        printf("Division by zero is not allowed\n");
        return;
    }

    handle = dlopen("./lib/libserver.so", RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "%s\n", dlerror());
        return;
    }

    dlerror();

    div_fn = (op_fn)dlsym(handle, "div");

    error = dlerror();
    if (error)
    {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return;
    }

    printf("Division = %d\n", div_fn(num1, num2));
    dlclose(handle);
}

/* Entry point function */
int main()
{
	int num1, num2, choice;

	printf("Enter the first number: \n");
	scanf("%d", &num1);

	printf("Enter the second number: \n");
	scanf("%d", &num2);

	printf("---------------------------------\n");
	printf("1. Add the numbers\n");
	printf("2. Subtract the numbers\n");
	printf("3. Multiply the numbers\n");
	printf("4. Divide the numbers\n");
	printf("---------------------------------\n");
	printf("Enter the choice:\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			call_add(num1, num2);
			break;
		case 2:
			call_sub(num1, num2);
			break;
		case 3:
			call_mul(num1, num2);
			break;
		case 4:
			call_div(num1, num2);
			break;
		default:
			printf("Enter a valid choice\n");
	}

	return 0;
}
