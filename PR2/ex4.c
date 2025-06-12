#include <stdio.h>

void removeChar(char *str, char ch)
{
    char *src = str, *dest = str;
    while (*src)
    {
        if (*src != ch)
        {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';
}

int main()
{
    char str[100], ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a character to delete: ");
    scanf(" %c", &ch);

    removeChar(str, ch);

    printf("Corrected string: %s", str);

    return 0;
}