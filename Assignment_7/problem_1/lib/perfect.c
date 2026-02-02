#include <stdio.h>
#include "perfect.h"
#include "helper.h"   // direct dependency

int is_perfect(int no)
{
    int sum = sum_of_factors(no);

    if (no == sum) {
        printf("%d is a perfect number\n", no);
        return 1;
    } else {
        printf("%d is not a perfect number\n", no);
        return 0;
    }
}

