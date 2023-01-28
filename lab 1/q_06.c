#include <stdio.h>
#include <stdlib.h>

int *sieve(int n)
{
    int *primes = (int *)malloc((n + 1) * sizeof(int));
    int i, j;

    for (i = 2; i <= n; i++)
        primes[i] = i;

    i = 2;
    while ((i * i) <= n)
    {
        if (primes[i] != 0)
        {
            for (j = 2; j < n; j++)
            {
                if (primes[i] * j > n)
                    break;
                else
                    primes[primes[i] * j] = 0;
            }
        }
        i++;
    }

    return primes;
}

void update_freq(int *dig, int num)
{
    int d;
    while (num > 0)
    {
        d = num % 10;
        dig[d]++;
        num /= 10;
    }
}

int find_max(int *dig)
{
    int d = 0;
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (dig[i] >= max)
        {
            d = i;
            max = dig[i];
        }
    }
    return d;
}

int main()
{
    int digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int a, b;
    scanf("%d %d", &a, &b);
    int *primes = sieve(b);
    primes[0] = primes[1] = 0;
    for (int i = a; i <= b; i++)
    {
        if (primes[i])
        {
            update_freq(digits, i);
        }
    }
    int id = find_max(digits);
    printf("%d %d\n", id, digits[id]);
}