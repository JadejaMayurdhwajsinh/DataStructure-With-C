#include <stdio.h>
#include <string.h>
int main()
{
    char str[20] = "arktik";
    int len = strlen(str);
    char k = 'k';
    char *s;
    s = str;
    while (*s != '\0')
    {
        if (*s == k)
        {
            char *t = s;
            while (*t != '\0')
            {
                *t = *(t + 1);
                t++;
            }
        }
        s++;
    }
    printf("%s", str);
    return 0;
}