#include <stdio.h>
#include <stdlib.h>
#define int long long

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int n;
    scanf("%lld", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int gcd_from_start[n];
    gcd_from_start[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        gcd_from_start[i] = gcd(gcd_from_start[i - 1], arr[i]);
    }
    int gcd_from_end[n];
    gcd_from_end[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        gcd_from_end[i] = gcd(gcd_from_end[i + 1], arr[i]);
    }
    int max_gcd = 0;
    for (int i = 0; i < n; i++)
    {
        int temp_gcd;
        if (i == 0)
        {
            temp_gcd = gcd_from_end[i + 1];
        }
        else if (i == n - 1)
        {
            temp_gcd = gcd_from_start[i - 1];
        }
        else
        {
            temp_gcd = gcd(gcd_from_start[i - 1], gcd_from_end[i + 1]);
        }
        if (temp_gcd > max_gcd)
        {
            max_gcd = temp_gcd;
        }
    }
    printf("%lld\n", max_gcd);
    return 0;
}