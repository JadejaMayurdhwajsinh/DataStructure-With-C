#include <stdio.h>
#include <string.h>
int compare(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0')
    {
        i++;
    }
    return str1[i] - str2[i];
}

void copystr(char *s1, char *s2)
{
    while (*s1 != '\0')
    {
        *s2 = *s1;
        *s1++;
        *s2++;
    }
    *s2 = '\0';
}

void concatstr(char *s1, char *s2)
{
    int j = strlen(s1), i = 0;
    while (s2[i] != '\0')
    {
        s1[j++] = s2[i++];
    }
    s1[j] = '\0';
}

void main()
{
    char str[10];
    char str2[10];
    char str3[10];
    printf("\n enter string 1 ");
    scanf(" %[^\n]", str);
    printf("\n enter string 2 ");
    scanf(" %[^\n]", str2);
    copystr(str, str3);
    printf("\n copied string is %s", str3);
    concatstr(str, str2);
    printf("\n concated string is %s", str);
    int res = compare(str, str2);
    if (res == 0)
    {
        printf("\n string is same");
    }
    else if (res > 0)
    {
        printf("\n str1 is greater");
    }
    else
    {
        printf("\n str2 is greater");
    }
}