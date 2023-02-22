#include <stdio.h>
#include <stdlib.h>

int n_trailing_zeroes_in_factorial(int n)
{
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        count += n / i;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int trail[n];

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        trail[i] = n_trailing_zeroes_in_factorial(arr[i]);
        if (trail[i] > max)
        {
            max = trail[i];
        }
    }

    int max_trail[max + 1];
    for (int i = 0; i <= max; i++)
    {
        max_trail[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        max_trail[trail[i]]++;
    }
    int total = 0;
    for (int i = 0; i <= max; i++)
    {
        total += max_trail[i] * (max_trail[i] - 1) / 2;
    }
    printf("%d\n", total);
    return 0;
}