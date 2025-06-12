#include <stdio.h>
#include "char_stack.c"

int main()
{
    char filename[100];
    printf("Enter the filename to check: ");
    scanf("%s", filename);

    checkBalancedParentheses(filename);
    return 0;
}