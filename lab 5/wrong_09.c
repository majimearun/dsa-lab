#include <stdio.h>
//  currently almost correct, some edge cases fails: why??

int find_n_kool(int arr[], int n, int k, int odd_posns[])
{
    int l, r;
    l = r = 0;
    int count = arr[0] % 2 ? 1 : 0;
    int n_arr = 0;
    int flag = 0;
    int posn = 0;
    int i = 0;
    if (arr[0] % 2)
    {
        odd_posns[0] = 0;
    }
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
                odd_posns[count - 1] = r;
                if (flag == 0)
                {
                    // identifying position of first odd number in the window
                    flag = 1;
                    posn = odd_posns[i] != -1 ? odd_posns[i] : r;
                }
            }
        }
        if (r == n)
        {
            break;
        }
        if (count == k)
        {
            n_arr = n_arr + (posn - l + 1);
            while (r < n - 1 && arr[r + 1] % 2 == 0)
            {
                r++;
                n_arr = n_arr + (posn - l + 1);
            }
        }

        while (count == k)
        {
            if (arr[l] % 2)
            {
                count--;
            }
            l++;
        }
        flag = 0;
        i++;
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
    for (int i = 0; i < n; i++)
    {
        odd_posns[i] = -1;
    }
    int n_kool = find_n_kool(arr, n, k, odd_posns);
    printf("%d\n", n_kool);
    return 0;
}