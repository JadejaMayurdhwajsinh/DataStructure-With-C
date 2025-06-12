#include "char_stack.c"
#include <stdio.h>
int main()
{
    CHAR_STACK *s = createStack(10);
    push(s, 'a');
    push(s, 'b');
    push(s, 'c');
    // display(s);
    printf("%c", pop(s));
    printf("%c", pop(s));
    printf("%c", peak(s));
    printf("\n");
    display(s);
    stackDestroy(s);
    return 0;
}