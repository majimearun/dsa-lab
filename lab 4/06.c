#include <stdio.h>
#include <stdlib.h>

void merge_sort_wrt_index(int arr[], int index[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort_wrt_index(arr, index, start, mid);
    merge_sort_wrt_index(arr, index, mid + 1, end);
    int *temp = malloc(sizeof(int) * (end - start + 1));
    int *temp2 = malloc(sizeof(int) * (end - start + 1));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = index[i];
            temp2[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = index[j];
            temp2[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = index[i];
        temp2[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = index[j];
        temp2[k] = arr[j];
        j++;
        k++;
    }
    for (int i = start; i <= end; i++)
    {
        index[i] = temp[i - start];
        arr[i] = temp2[i - start];
    }
    free(temp);
    free(temp2);
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int index[n];
    for (int i = 0; i < n; i++)
    {
        index[i] = i;
    }
    int votes[n];
    for (int i = 0; i < n; i++)
    {
        votes[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        votes[arr[i] - 1]++;
    }
    merge_sort_wrt_index(votes, index, 0, n - 1);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", index[n - i - 1] + 1);
    }
    printf("\n");
    return 0;
}