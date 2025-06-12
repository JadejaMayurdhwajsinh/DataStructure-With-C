#include <stdio.h>

int main()
{
    int src[100], dest[200];
    int *p1, *p2;
    int n, i;

    printf("Enter number of elements in source array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &src[i]);
    }

    p1 = src;
    p2 = dest;

    for (i = 0; i < n; i++)
    {
        *(p2 + i) = *(p1 + i);
    }

    printf("Elements of destination array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", dest[i]);
    }

    return 0;
}