#include <stdio.h>
#include <stdlib.h>
#define int unsigned long long

int find_sqrt(int start, int end, int num)
{
    int mid = (start + end) / 2;
    if ((start + end) % 2)
    {
        mid++;
    }
    if (start == end)
    {
        return start;
    }
    if ((mid * mid) < num)
    {
        return find_sqrt(mid, end, num);
    }
    else if ((mid * mid) > num)
    {
        return find_sqrt(start, mid - 1, num);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int n;
    scanf("%lld", &n);
    int sqrt = find_sqrt(1, n, n);
    printf("%lld\n", sqrt);
    return 0;
}