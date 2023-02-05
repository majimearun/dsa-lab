#include <stdio.h>
#include <stdlib.h>

void subset_sum(int *arr, int n, int target_sum, int *presence, int pres_len)
{
    if (target_sum == 0)
    {
        printf("POSSIBLE\n");
        for (int i = n; i < pres_len; i++)
        {
            if (presence[i])
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        exit(0);
    }
    if (n > 0)
    {
        presence[n - 1] = 1;
        subset_sum(arr, n - 1, target_sum - arr[n - 1], presence, pres_len);
        presence[n - 1] = 0;
        subset_sum(arr, n - 1, target_sum, presence, pres_len);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int target_sum;
    scanf("%d", &target_sum);
    int *pres = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        pres[i] = 0;
    }
    subset_sum(arr, n, target_sum, pres, n);
    printf("NOT POSSIBLE\n");
    // TODO: free pointers
    return 0;
}