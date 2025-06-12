#include <stdio.h>

int linearsearch(int arr[], int elem, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        if (arr[i] == elem)
        {
            printf("\nLinear Search Iterations: %d", count);
            return i;
        }
    }
    printf("\nLinear Search Iterations: %d", count);
    return -1;
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binarysearch(int arr[], int n, int elem)
{
    sort(arr, n);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int start = 0, end = n - 1, count = 0;

    while (start <= end)
    {
        count++;
        int mid = (start + end) / 2;
        if (elem == arr[mid])
        {
            printf("\nBinary Search Iterations: %d", count);
            return mid;
        }
        else if (elem < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    printf("\nBinary Search Iterations: %d", count);
    return -1;
}

int main()
{
    int n, target;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    int linearIndex = linearsearch(arr, target, n);
    printf("\nLinear Search Result: Index %d", linearIndex);

    int binaryIndex = binarysearch(arr, n, target);
    printf("\nBinary Search Result: Index %d", binaryIndex);

    return 0;
}
