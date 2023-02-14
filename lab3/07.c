#include <stdio.h>
#include <stdlib.h>
#define int long long

int find_max_deduction(int *arr, int start, int end, int k)
{
    int mid;
    if ((start + end) % 2)
    {
        mid = ((start + end) / 2) + 1;
    }
    else
    {
        mid = (start + end) / 2;
    }
    if (start == end)
    {

        return arr[start];
    }
    if (arr[mid] == k)
    {
        return mid;
    }
    else
    {
        if (arr[mid] < k)
        {
            return find_max_deduction(arr, mid, end, k);
        }
        else
        {
            return find_max_deduction(arr, start, mid - 1, k);
        }
    }
}

int main()
{
    int n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int max = find_max_deduction(arr, 0, n, k);
    printf("%lld\n", max);
    return 0;
}