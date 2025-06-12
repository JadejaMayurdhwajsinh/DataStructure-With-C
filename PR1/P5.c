#include <stdio.h>

int main()
{
    int *b[5];
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        b[i] = &arr[i];
    }
    for (int i = 0; i < 5; i++)
    {
        printf("address is %d ", b[i]);
        printf("and value is %d ", *(b[i]));
        printf("\n");
    }
    return 0;
}