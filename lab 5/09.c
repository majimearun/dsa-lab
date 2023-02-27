#include <stdio.h>

int find_n_kool(int arr[], int n, int k)
{
    int l = 0;
    int n_arr, odd_count;
    n_arr = odd_count = 0;
    int curr_sub_array_count = 0;

    for (int r = 0; r < n; r++)
    {
        if (arr[r] % 2)
        {
            odd_count++;
            curr_sub_array_count = 0;
        }
        while (odd_count == k)
        {
            if (arr[l] % 2)
            {
                odd_count--;
            }
            l++;
            curr_sub_array_count++;
        }
        n_arr += curr_sub_array_count;
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
    int odd_posns[n];
    int n_kool = find_n_kool(arr, n, k);
    printf("%d\n", n_kool);
    return 0;
}