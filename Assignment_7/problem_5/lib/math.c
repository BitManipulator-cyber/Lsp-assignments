/**
 * Functions implemented:
 *  - my_pow        : calculates power of a number (base^exponent)
 *  - my_sqrt       : returns approximate square root of a number
 *  - my_abs        : returns absolute value of a number
 *  - my_max        : returns maximum of two numbers
 *  - my_min        : returns minimum of two numbers
 *  - my_factorial  : calculates factorial of a number
 *  - my_gcd        : calculates greatest common divisor of two numbers
 *  - my_lcm        : calculates least common multiple of two numbers
 */

int my_pow(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

/* Square root (approx) */
int my_sqrt(int n)
{
    int i = 0;
    while (i * i <= n)
        i++;
    return i - 1;
}

/* Absolute value */
int my_abs(int n)
{
    return (n < 0) ? -n : n;
}

/* Maximum */
int my_max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Minimum */
int my_min(int a, int b)
{
    return (a < b) ? a : b;
}

/* Factorial */
int my_factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

/* GCD */
int my_gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* LCM */
int my_lcm(int a, int b)
{
    return (a * b) / my_gcd(a, b);
}
