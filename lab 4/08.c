#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rooms;
    int kings;
    scanf("%d %d", &kings, &rooms);
    int max = kings - rooms + 1;
    max = max * (max - 1) / 2;
    int min, min_plus;
    min_plus = kings % rooms;
    min = rooms - min_plus;
    int min_kings = kings / rooms;
    int min_sum = min_kings * (min_kings - 1) / 2;
    int min_plus_sum = min_kings * (min_kings + 1) / 2;
    min = (min * min_sum) + (min_plus * min_plus_sum);
    printf("%d %d", min, max);
    return 0;
}