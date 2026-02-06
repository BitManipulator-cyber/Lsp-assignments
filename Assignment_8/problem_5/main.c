#include <stdio.h>
#include "mathlib.h"

int main()
{
	int a = 10, b = 5;

	printf("Addition = %d\n", add(a, b));
	printf("Subtraction = %d\n", sub(a, b));
	printf("Multiplication = %d\n", mul(a, b));
	printf("Division = %d\n", div(a, b));
}
