#include <string.h>
#include <stdio.h>

void count_letters_and_digits(char str[])
{
    int uppercase = 0, lowercase = 0, digits = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')   // ignore newline from fgets
            continue;

        if (str[i] >= 'A' && str[i] <= 'Z')
            uppercase++;
        else if (str[i] >= 'a' && str[i] <= 'z')
            lowercase++;
        else if (str[i] >= '0' && str[i] <= '9')
            digits++;
    }

    printf("Number of upper case = %d\n", uppercase);
    printf("Number of lower case = %d\n", lowercase);
    printf("Number of digits     = %d\n", digits);
}
