#include <stdio.h>
#include "char_stack.c"

void main()
{
    CHAR_STACK *s = createStack(100);
    reverseString(s);
    // printf("\n reversed string is %s", s->name);
    stackDestroy(s);
}