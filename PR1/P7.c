#include <stdio.h>

int main()
{
    int n;
    printf("\n enter the n");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *p;
    p = &arr[n - 1];
    for (int i = 0; i < n; i++)
    {
        printf("%d", *(p - i));
    }
    return 0;
}