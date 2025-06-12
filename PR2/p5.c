// Write a C Program to check whether the string entered by the user is a palindrome string
// or not using a pointer

#include <stdio.h>
#include <string.h>
int main()
{
    char str1[20];
    char str[20];
    printf("\n Enter the string");
    scanf(" %[^\n]", str1);
    // strcpy(str, str1);
    int len = strlen(str1);
    char *s, *e;
    s = str1;
    e = &str1[len - 1];
    while (s <= e)
    {
        char temp = *s;
        *s = *e;
        *e = temp;
        s++;
        e--;
    }
    if (*s == *e)
    {
        printf("\n string is palindrom");
    }
    else
    {
        printf("\n string is not palindrom");
    }
}