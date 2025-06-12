#include <stdio.h>

// ✅ Bubble Short ✅
void bubble(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ✅ Linear Search ✅
int linear(int arr[], int n, int target)
{
    int iteration = 0;
    for (int i = 0; i < n; i++)
    {
        iteration += 1;
        if (arr[i] == target)
        {
            printf("Iteration %d ", iteration);
            return i;
        }
    }
    printf("Iteration %d ", iteration);
    return -1;
}

// ✅ Binary Search ✅
int binary(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    int iteration = 0;
    while (start <= end)
    {
        iteration++;
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            printf("Binary Search Iteration %d ", iteration);
            return mid;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    printf("Binary Search Iteration %d ", iteration);
    return -1;
}

// ✅ INSERTION COMPLETE✅
void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i;
        while (j != 0 && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

// ✅ Merge 2 shorted Array ✅
void merge(int arr1[], int arr2[], int n1, int n2)
{
    int n3 = n1 + n2;
    int arr3[n3];
    int i = 0, j = 0, idx = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] > arr2[j])
        {
            arr3[idx++] = arr2[j++];
        }
        else
        {
            arr3[idx++] = arr1[i++];
        }
    }

    while (i < n1)
    {
        arr3[idx++] = arr1[i++];
    }

    while (j < n2)
    {
        arr3[idx++] = arr2[j++];
    }

    for (int i = 0; i < n3; i++)
    {
        printf("%d ", arr3[i]);
    }
}

void mergeFinal(int arr[], int left, int right, int mid)
{
    int size = (right - left) + 1;
    int newArr[size];
    int i = left;
    int j = mid + 1;
    int idx = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] > arr[j])
        {
            newArr[idx++] = arr[j++];
        }
        else
        {
            newArr[idx++] = arr[i++];
        }
    }

    while (i <= mid)
    {
        newArr[idx++] = arr[i++];
    }

    while (j <= right)
    {
        newArr[j] = arr[j++];
    }

    for (int i = 0; i < size; i++)
    {
        arr[left + i] = newArr[i];
    }
}

// ✅ Devide and Conquer Merge Sort ✅
void mergesort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    mergeFinal(arr, left, right, mid);
}

// ✅Quick Sort ✅//
int partition_first(int arr[], int low, int high)
{
    int pivot = arr[low]; 

    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_first(arr, low, high); // 👈 use partition_first
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    int arr1[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int left = 0;
    int right = (sizeof(arr1) / sizeof(arr1[0])) - 1;
    mergesort(arr1, left, right);
    for (int i = 0; i <= right; i++)
    {
        printf("%d ", arr1[i]);
    }
}