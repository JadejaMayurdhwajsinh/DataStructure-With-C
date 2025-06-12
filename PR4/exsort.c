#include <stdio.h>
#include "char_stack.c"

int main()
{
    Stack *s = createStack(10);
    push(s, 34);
    push(s, 3);
    push(s, 31);
    push(s, 98);
    push(s, 92);
    push(s, 23);

    printf("Original Stack:\n");
    display(s);

    sortStack(s);

    printf("Sorted Stack:\n");
    display(s);

    free(s->name);
    free(s);
    return 0;
}