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
    int a, b;
    scanf("%lld %lld", &a, &b);
    int max_coprime = 0;
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            if (gcd(i, b) == 1)
            {
                if (i > max_coprime)
                {
                    max_coprime = i;
                }
            }
            if (gcd(a / i, b) == 1)
            {

                if (a / i > max_coprime)
                {
                    max_coprime = a / i;
                }
            }
        }
    }
    printf("%lld\n", max_coprime);
    return 0;
}