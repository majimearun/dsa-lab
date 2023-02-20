#include <stdio.h>
#include <stdlib.h>
#define int long long

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

int *count_n_primes_till(int n)
{
    int *primes = sieve(n);
    int *count = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        count[i] = 0;
    }
    int curr_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (primes[i] != 0)
        {
            curr_count++;
        }
        count[i] = curr_count;
    }
    return count;
}

int main()
{
    int n, q;
    scanf("%lld", &n);
    scanf("%lld", &q);
    int *primes = count_n_primes_till(n);
    int *queries = (int *)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++)
    {
        scanf("%lld", &queries[i]);
    }
    for (int i = 0; i < q; i++)
    {
        printf("%lld ", primes[queries[i]]);
    }
    printf("\n");
    return 0;
}