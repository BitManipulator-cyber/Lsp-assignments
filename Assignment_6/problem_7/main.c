/**
 * Author: Aaditya Jagtap
 * Problem Statement: Write a dynamically linked client 
 * program to demonstrate persistence of the global 
 * varible across multiple function calls
 */

/* Header files */
#include "lib/calc.h"

/* Entry point funtion */
int main()
{
	/* global_var = 4 */
	modify(4);
	/* Now 4 */
	display();

	/* Again setting it to zero */
	reset();

	/* Display and modify again */
	display();
	modify(16);

	display();
	reset();

	return 0;
}
