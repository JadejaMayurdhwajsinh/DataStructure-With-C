#include <stdio.h>

int main()
{
    int n = 4;
    int storeSale[n][n];
    int *ptr = storeSale[0];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Data For Comapanie %d", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("\nEnter Data For Quater %d :", j + 1);
            scanf("%d", (ptr + i * n + j));
        }
    }
    printf("\n\t\tQuater 1\tQuater 2\tQuater 3\tQuater 4");
    for (int i = 0; i < n; i++)
    {
        printf("\nCompanie %d\t", i + 1);
        for (int j = 0; j < n; j++)
            printf("%d\t\t", *(ptr + i * n + j));
    }
    return 0;
}