#include <stdio.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("\n after swapping a= %d ", a);
    printf("\n after swapping b= %d ", b);
}

void Refference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    printf("\n enter a and b ");
    scanf("%d %d", &a, &b);
    swap(a, b);
    Refference(&a, &b);
    printf("\n after swapping By Refference a= %d ", a);
    printf("\n after swapping By Refference b= %d ", b);
    return 0;
}