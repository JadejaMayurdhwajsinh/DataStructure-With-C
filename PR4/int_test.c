#include <stdio.h>
#include "int_stack.c"
#include <stdlib.h>

int main()
{
    INT_STACK *s = createStack(10);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    // display(s);
    printf("%d", pop(s));
    printf("%d", pop(s));
    printf("%d", peak(s));
    printf("\n");
    display(s);
    stackDestroy(s);
    return 0;
}