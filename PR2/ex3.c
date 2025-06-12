#include <stdio.h>

float average(float *arr, int m)
{
    float sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += *(arr + i);
    }
    return sum / m;
}

int main()
{
    float numbers[10];
    int i, m;
    float result;

    printf("Enter 10 float numbers:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%f", &numbers[i]);
    }

    printf("Enter the number of elements to average (m): ");
    scanf("%d", &m);

    if (m > 0 && m <= 10)
    {
        result = average(numbers, m);
        printf("Average of first %d numbers: %.2f\n", m, result);
    }
    else
    {
        printf("Invalid value of m\n");
    }

    return 0;
}