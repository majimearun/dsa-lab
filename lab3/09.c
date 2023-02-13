#include <stdio.h>
#include <stdlib.h>
#define int long

int find_half_time(int start, int end, int num, int half)
{
    int mid = (start + end) / 2;
    int calc = (mid * num) - ((mid * (mid + 1)) / 2);
    if (calc == half || start == end)
    {
        return mid;
    }
    if (calc > half)
    {
        return find_half_time(start, mid, num, half);
    }
    else
    {
        return find_half_time(mid + 1, end, num, half);
    }
}

int main()
{
    int n;
    scanf("%ld", &n);
    int half = (n * (n - 1) / 2)/2;
    int ht = find_half_time(1, n, n, half);
    printf("%ld\n", ht);
    return 0;
}