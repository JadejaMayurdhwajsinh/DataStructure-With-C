#include "stdio.h"
#include "stdlib.h"

void main()
{
    int n = 5;
    int *arr = (int *)calloc(n, sizeof(int));
    printf("\n address = %d", arr);
    printf("\n value = ");
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    printf("\n\nSum : %d", sum);

    int m = 3;
    arr = (int *)realloc(arr, (m + n) * sizeof(int));
    sum = 0;

    for (int i = n; i < (m + n); i++)
    {
        scanf("%d ", (arr + i));
    }
    printf("\n address = %d", arr);
    printf("\n value =");
    // for (int i = 0; i < (m + n); i++)
    // {
    //     printf("%d ", *(arr + i));
    // }
    for (int i = 0; i < (m + n); i++)
    {
        sum += *(arr + i);
        printf("%d ", *(arr + i));
    }

    printf("\n\nSum : %d", sum);
}