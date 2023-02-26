#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    int c = 0;
    int prev = 0;
    int curr = 0;
    while (c < n)
    {
        scanf("%d", &curr);
        c++;
        int p = (rand() % c) + 1;
        if (p == c)
        {
            printf("%d\n", curr);
            prev = curr;
        }
        else
        {
            printf("%d\n", prev);
        }
    }
    return 0;
}