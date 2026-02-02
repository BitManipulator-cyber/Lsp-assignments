/**
 * Functions implemented:
 * 	- my_strlen : return length of a string
 * 	- my_strcpy : copy one string into another
 * 	- my_strcat : used to concatenate two strings
 * 	- my_strcmp : compares two strings
 * 	- my_strncmp: compares specified number of characters
 * 	- my_strrev : reverse a string
 * 	- my_strchr : used to find occurece of the character in a string
 */

#include <stdio.h>

/* String length */
int my_strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

/* String copy */
char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/* String copy with limit */
char *my_strncpy(char *dest, const char *src, int n)
{
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    for (; i < n; i++)
        dest[i] = '\0';

    return dest;
}

/* String concatenation */
char *my_strcat(char *dest, const char *src)
{
    int i = 0, j = 0;

    while (dest[i] != '\0')
        i++;

    while (src[j] != '\0')
        dest[i++] = src[j++];

    dest[i] = '\0';
    return dest;
}

/* String compare */
int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

/* String compare with limit */
int my_strncmp(const char *s1, const char *s2, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return s1[i] - s2[i];
    }
    return 0;
}

/* String reverse */
void my_strrev(char *str)
{
    int i = 0, j = my_strlen(str) - 1;
    char temp;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

/* Find character in string */
char *my_strchr(const char *str, char ch)
{
    while (*str)
    {
        if (*str == ch)
            return (char *)str;
        str++;
    }
    return NULL;
}
