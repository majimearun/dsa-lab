#include <stdio.h>
#include <stdlib.h>

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
    scanf("%d %d", &a, &b);
    int max_coprime = 0;
    for (int i = 0; i < a; i++)
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
        }
    }
    printf("%d", max_coprime);
}