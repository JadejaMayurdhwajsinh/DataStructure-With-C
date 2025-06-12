// Write a C program to count vowels and consonants in a string using a pointer

#include <stdio.h>
#include <ctype.h>
int main()
{
    int vowel = 0, consonant = 0;
    char str[20];
    printf("Enter the string");
    scanf(" %[^\n]", str);
    char *s = str;
    while (*s != '\0')
    {
        if (isalpha(*s))
        {
            if (*s == 'a' || *s == 'A' || *s == 'i' || *s == 'I' || *s == 'o' || *s == 'O' || *s == 'u' || *s == 'U' || *s == 'e' || *s == 'E')
            {
                vowel += 1;
            }
            else
            {
                consonant += 1;
            }
        }
        s++;
    }
    printf("\n vowel = %d ", vowel);
    printf("\n consonant = %d ", consonant);
    return 0;
}