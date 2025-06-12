#include <stdio.h>

int main()
{
    int arr[15];
    for (int i = 0; i < 15; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *p;
    p = arr;
    printf("\n base address of array is %d ", p);
    printf("\n array elements are \n");
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", *(p + i));
    }
    return 0;
}