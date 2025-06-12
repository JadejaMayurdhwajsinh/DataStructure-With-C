#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;
    int **q;
    q = &p;
    printf("\n value of a is %d ", a);
    printf("\n value of a is %d ", *p);
    printf("\n value of a is %d ", **q);
    printf("\n address of a is %d ", &a);
    printf("\n address of a is %d ", p);
    printf("\n address of a is %d ", *q);
    printf("\n address of pointer p is %d ", &p);
    printf("\n address of pointer p is %d ", q);
    printf("\n address of pointer q is %d ", &q);
}