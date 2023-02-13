#include <stdio.h>
#include <stdlib.h>

int sum(int *arr, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    return s;
}

int max(int *arr, int n)
{
    int m = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}

int check(int *arr, int n, int size, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += arr[i] / size;
        if (count >= k)
        {
            return 1;
        }
    }
    return 0;
}

int find_best_size(int *arr, int start, int end, int k, int n)
{
    int mid = (start + end) / 2;
    if ((start + end) % 2)
    {
        mid++;
    }
    if (start == end)
    {
        return mid;
    }
    if (check(arr, n, mid, k))
    {
        return find_best_size(arr, mid, end, k, n);
    }
    else
    {
        return find_best_size(arr, start, mid - 1, k, n);
    }
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int size = find_best_size(arr, 0, n - 1, k, n);
    printf("%d\n", size);
}
