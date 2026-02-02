#include <stdio.h>
#include "helper.h"

int sum_of_factors(int no)
{
	int sum = 0;

	for(int i = 1; i < no; i++)
	{
		if(no % i == 0)
		{
			sum += i;
		}
	}
	return sum;
}

