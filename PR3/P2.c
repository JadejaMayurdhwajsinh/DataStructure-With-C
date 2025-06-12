#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, *new_arr;
    int n, n2, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Address: %p Value: %d\n", (void *)&arr[i], arr[i]);
    }

    printf("Enter the new size: ");
    scanf("%d", &n2);

    new_arr = (int *)realloc(arr, n2 * sizeof(int));

    if (n2 > n)
    {
        printf("Enter %d more elements:\n", n2 - n);
        for (i = n; i < n2; i++)
        {
            scanf("%d", &new_arr[i]);
        }
    }

    printf("Modified array:\n");
    for (i = 0; i < n2; i++)
    {
        printf("Address: %p Value: %d\n", (void *)&new_arr[i], new_arr[i]);
    }

    free(new_arr);
    return 0;
}