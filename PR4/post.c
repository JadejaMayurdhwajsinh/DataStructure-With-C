#include <stdio.h>
#include "char_stack.c"
#include <ctype.h>
#include <string.h>

int main()
{
    CHAR_STACK *s = createStack(20);
    printf("\n enter postfix expression there is only + - * / % ^ operands\n");
    // printf("\n add ) at last");
    scanf("%s", s->name);
    eval(s);
}