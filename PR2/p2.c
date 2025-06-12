// Write a C program to compare two strings using pointers.

#include <stdio.h>

int main()
{
    char str[20];
    char str2[20];
    printf("\n Enter the string1");
    scanf(" %[^\n]", str);
    printf("\n Enter the string2");
    scanf(" %[^\n]", str2);
    char *s;
    s = str;
    char *s1;
    s1 = str2;
    while (*s == *s1 && *s != '\0')
    {
        s++;
        s1++;
    }
    int ans = *s - *s1;
    printf("%d", ans);
    if (*s == '\0' && *s1 == '\0')
    {
        printf("\n Both strings are equal");
    }
    else
    {
        printf("\n Both strings are not equal");
    }

    return 0;
}