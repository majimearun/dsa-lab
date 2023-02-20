#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    int *temp = malloc(sizeof(int) * (end - start + 1));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
    free(temp);
}
int main()
{
    int n;
    scanf("%d", &n);
    int doggos[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &doggos[i]);
    }
    mergeSort(doggos, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (doggos[i] <= n - i)
        {
            printf("%d\n", doggos[i]);
            return 0;
        }
    }
    return 0;
}