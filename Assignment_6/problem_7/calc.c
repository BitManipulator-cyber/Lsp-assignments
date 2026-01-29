/* Implementation of those functions in this file */

#include <stdio.h>
#include "calc.h"

/* The global variable intial value will be zero */
int global_var = 0;

/**
 * modify - modifies value of global variable
 *
 * @x : the change in global variable
 *
 * This funtion changes the value of global variable 
 * by x i.e., add the 'x' to the global variable 
 */
void modify(int x)
{
	global_var += x;
}

void display(void)
{
	printf("The value of global variable = %d\n", global_var);
}

void reset(void)
{
	global_var = 0;
}
