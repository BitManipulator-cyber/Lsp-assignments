#include <stdio.h>

/* String functions */
int my_strlen(const char *);
char *my_strcpy(char *, const char *);
char *my_strncpy(char *, const char *, int);
char *my_strcat(char *, const char *);
int my_strcmp(const char *, const char *);
int my_strncmp(const char *, const char *, int);
void my_strrev(char *);
char *my_strchr(const char *, char);

/* Math functions */
int my_pow(int, int);
int my_sqrt(int);
int my_abs(int);
int my_max(int, int);
int my_min(int, int);
int my_factorial(int);
int my_gcd(int, int);
int my_lcm(int, int);

void string_menu()
{
    char str1[100], str2[100], str3[100], ch;
    int n, choice;

    printf("\n===== STRING FUNCTIONS =====\n");
    printf("1. String Length (my_strlen)\n");
    printf("2. String Copy (my_strcpy)\n");
    printf("3. String Copy N characters (my_strncpy)\n");
    printf("4. String Concatenate (my_strcat)\n");
    printf("5. String Compare (my_strcmp)\n");
    printf("6. String Compare N characters (my_strncmp)\n");
    printf("7. String Reverse (my_strrev)\n");
    printf("8. Find Character (my_strchr)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter string: ");
        scanf("%s", str1);
        printf("Length: %d\n", my_strlen(str1));
        break;

    case 2:
        printf("Enter source string: ");
        scanf("%s", str1);
        printf("Copied string: %s\n", my_strcpy(str2, str1));
        break;

    case 3:
        printf("Enter source string: ");
        scanf("%s", str1);
        printf("Enter number of characters to copy: ");
        scanf("%d", &n);
        printf("Copied string: %s\n", my_strncpy(str2, str1, n));
        break;

    case 4:
        printf("Enter first string: ");
        scanf("%s", str1);
        printf("Enter second string: ");
        scanf("%s", str2);
        my_strcpy(str3, str1); // Copy str1 to str3 first
        printf("Concatenated string: %s\n", my_strcat(str3, str2));
        break;

    case 5:
        printf("Enter first string: ");
        scanf("%s", str1);
        printf("Enter second string: ");
        scanf("%s", str2);
        printf("Compare result: %d\n", my_strcmp(str1, str2));
        printf("(0 = equal, <0 = first < second, >0 = first > second)\n");
        break;

    case 6:
        printf("Enter first string: ");
        scanf("%s", str1);
        printf("Enter second string: ");
        scanf("%s", str2);
        printf("Enter number of characters to compare: ");
        scanf("%d", &n);
        printf("Compare result: %d\n", my_strncmp(str1, str2, n));
        break;

    case 7:
        printf("Enter string: ");
        scanf("%s", str1);
        my_strrev(str1);
        printf("Reversed string: %s\n", str1);
        break;

    case 8:
        printf("Enter string: ");
        scanf("%s", str1);
        printf("Enter character to find: ");
        scanf(" %c", &ch);
        char *result = my_strchr(str1, ch);
        if (result)
            printf("Character found at position: %ld\n", result - str1);
        else
            printf("Character not found\n");
        break;

    default:
        printf("Invalid choice!\n");
    }
}

void math_menu()
{
    int a, b, choice;

    printf("\n===== MATH FUNCTIONS =====\n");
    printf("1. Power (my_pow)\n");
    printf("2. Square Root (my_sqrt)\n");
    printf("3. Absolute Value (my_abs)\n");
    printf("4. Maximum (my_max)\n");
    printf("5. Minimum (my_min)\n");
    printf("6. Factorial (my_factorial)\n");
    printf("7. GCD (my_gcd)\n");
    printf("8. LCM (my_lcm)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter base: ");
        scanf("%d", &a);
        printf("Enter exponent: ");
        scanf("%d", &b);
        printf("Result: %d\n", my_pow(a, b));
        break;

    case 2:
        printf("Enter number: ");
        scanf("%d", &a);
        printf("Square root: %d\n", my_sqrt(a));
        break;

    case 3:
        printf("Enter number: ");
        scanf("%d", &a);
        printf("Absolute value: %d\n", my_abs(a));
        break;

    case 4:
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        printf("Maximum: %d\n", my_max(a, b));
        break;

    case 5:
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        printf("Minimum: %d\n", my_min(a, b));
        break;

    case 6:
        printf("Enter number: ");
        scanf("%d", &a);
        printf("Factorial: %d\n", my_factorial(a));
        break;

    case 7:
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        printf("GCD: %d\n", my_gcd(a, b));
        break;

    case 8:
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        printf("LCM: %d\n", my_lcm(a, b));
        break;

    default:
        printf("Invalid choice!\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== MAIN MENU =====\n");
        printf("1. String Functions\n");
        printf("2. Math Functions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            string_menu();
            break;
        case 2:
            math_menu();
            break;
        case 3:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
