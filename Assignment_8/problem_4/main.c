/**
 * Author: Aaditya Jagtap
 * Problem Statement: Dynamic implicit linking using Makefile
 */

#include <stdio.h>

/* Entry point function */
int main(void)
{
	int no1, no2;

	printf("Enter first number: ");
	scanf("%d", &no1);

	printf("Enter second number: ");
	scanf("%d", &no2);

	printf("Addition = %d\n", add(no1, no2));

	return 0;
}
