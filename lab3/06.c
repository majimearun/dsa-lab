#include <stdio.h>
#include <stdlib.h>

int find_last_occurence(int *arr, int start, int end, int team)
{
    int mid = (start + end) / 2;
    if (arr[mid] == team)
    {
        if (arr[mid + 1] != team)
        {
            return mid;
        }
        else
        {
            return find_last_occurence(arr, mid + 1, end, team);
        }
    }
    else if (arr[mid] > team)
    {
        return find_last_occurence(arr, start, mid - 1, team);
    }
    else
    {
        return find_last_occurence(arr, mid + 1, end, team);
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k = 0;
    int team = arr[0];
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        start = find_last_occurence(arr, start, end, team);
        if (start != -1)
        {
            start++;
            k++;
            team = arr[start];
        }
        else
        {
            break
        }
    }
    printf("%d\n", k);
}