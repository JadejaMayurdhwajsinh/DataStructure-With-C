#include "char_stack.c"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    CHAR_STACK *s = createStack(30);
    itop(s);
    return 0;
}