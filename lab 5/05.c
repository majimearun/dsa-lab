#include <stdio.h>

int find_max_bombs(int arr[], int n, int k)
{
    int l, r;
    l = r = 0;
    int count = arr[0] ? 0 : 1;
    int sum = 0;
    if (k > 0)
    {
        sum = 1;
    }
    int max_sum = 0;
    while (r < n)
    {
        while (count < k)
        {
            r++;
            if (r == n)
            {
                break;
            }
            if (!arr[r])
            {
                count++;
            }
            sum++;
        }
        if (r == n)
        {
            break;
        }
        if (count == k)
        {
            while (r < n - 1 && arr[r + 1] == 1)
            {
                r++;
                sum++;
            }
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }

        while (count == k)
        {
            if (!arr[l])
            {
                count--;
            }
            sum--;
            l++;
        }
    }
    return max_sum;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int bombs[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bombs[i]);
    }
    int dyn = find_max_bombs(bombs, n, k);
    printf("%d\n", dyn);
    return 0;
}