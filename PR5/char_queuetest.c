#include <stdio.h>
#include "char_cirque.c"

int main()
{
    queue *q = createqueue(5);
    enqueue(q, 'a');
    enqueue(q, 'b');
    enqueue(q, 'c');
    enqueue(q, 'd');
    enqueue(q, 'e');
    display(q);
    printf("\n");
    printf("%c", dequeue(q));
    printf("%c", dequeue(q));
    printf("\n");
    display(q);
    // reversequeue(q);
    // printf("\n in reverse \n");
    enqueue(q, 'e');
    enqueue(q, 'f');
    printf("\n");
    display(q);
    destroyqueue(q);
}