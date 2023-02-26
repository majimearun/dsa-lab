#include <stdio.h>
#include <stdlib.h>

int find_n_safe(int arr[], int n, int k)
{
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int rem[k];
    for (int i = 0; i < k; i++)
    {
        rem[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        rem[prefix[i] % k]++;
    }
    int n_safe = 0;
    for (int i = 0; i < k; i++)
    {
        if (rem[i] > 1)
        {
            n_safe += (rem[i] * (rem[i] - 1)) / 2;
        }
    }
    return n_safe + rem[0];
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int n_safe = find_n_safe(a, n, k);
    printf("%d\n", n_safe);
    return 0;
}