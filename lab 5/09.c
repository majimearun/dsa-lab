#include <stdio.h>

int find_n_kool(int arr[], int n, int k)
{
    int l, r;
    l = r = 0;
    int count = arr[0] % 2 ? 1 : 0;
    int n_arr = 0;
    while (r < n)
    {
        while (count < k)
        {
            r++;
            if (r == n)
            {
                break;
            }
            if (arr[r] % 2)
            {
                count++;
            }
        }
        if (r == n)
        {
            break;
        }
        if (count == k)
        {
            n_arr++;
        }

        while (count == k)
        {
            if (arr[l] % 2)
            {
                count--;
            }
            l++;
        }
    }
    return n_arr;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    int arr[n];
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int n_kool = find_n_kool(arr, n, k);
    printf("%d\n", n_kool);
    return 0;
}