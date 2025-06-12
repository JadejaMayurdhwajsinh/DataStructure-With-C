// Write a C program to create a function to accept a number and check whether it is even or odd. Call the function using a pointer to function.

#include <stdio.h>
void oddeven(int n)
{
    (n == 0) ? printf("0 is not odd or even") : (n % 2 == 0) ? printf("even")
                                                             : printf("odd");
}
int main()
{
    int n;
    printf("\n enter the number ");
    scanf("%d", &n);
    void (*fp)(int);
    fp = oddeven;
    fp(n);
    return 0;
}