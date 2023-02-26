#include <stdio.h>
#include <stdlib.h>
#define int long long

int kill(int n, int dir)
{

    if (n == 1)
    {
        return 1;
    }
    else if (dir == 0)
    {
        return 2 * kill(n / 2, 1);
    }
    else if (dir == 1)
    {
        if (n % 2 == 0)
        {
            return 2 * kill(n / 2, 0) - 1;
        }
        else
        {
            return 2 * kill(n / 2, 0);
        }
    }
}

int main()
{
    int n;
    scanf("%lld", &n);
    printf("%lld\n", kill(n, 0));
    return 0;
}