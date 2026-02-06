/**
 * Author: Aaditya Jagtap
 * Problem Statement: Print addition of 2 integers but using a Makefile
 */

/* Header files */
#include <stdio.h>

/* Addition function */
int add(int a, int b)
{
	return a + b;
}

/* Entry point function */
int main(void)
{
	int no1, no2;

	printf("Enter first number: ");
	scanf("%d", &no1);

	printf("Enter second number: ");
	scanf("%d", &no2);

	printf("Addition: %d\n", add(no1, no2));

	return 0;
}

/**
 * Commands to run:
 * 	(1) To compile:
 * 		> make
 * 	(2) To run the executable
 * 		> make run
 * 	(3) To clean and delete the executable
 * 		> make clean
 */
