#include <stdio.h>

int find_grps(int cum_sum_arr[], int n, int k, int thresh_avg)
{
    int count = 0;
    for (int start = 0; start < n - k + 1; start++)
    {
        if (start == 0)
        {
            if ((cum_sum_arr[start + k - 1]) / k >= thresh_avg)
            {
                count++;
            }
        }
        else if (start == n - k)
        {
            if ((cum_sum_arr[n - 1] - cum_sum_arr[start - 1]) / k >= thresh_avg)
            {
                count++;
            }
        }
        else
        {
            if ((cum_sum_arr[start + k - 1] - cum_sum_arr[start - 1]) / k >= thresh_avg)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n, k, thresh_avg;
    int sum = 0;
    scanf("%d %d %d", &n, &k, &thresh_avg);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int cum_sum[n];
    cum_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        cum_sum[i] = cum_sum[i - 1] + arr[i];
    }
    int grps = find_grps(cum_sum, n, k, thresh_avg);
    printf("%d\n", grps);
    return 0;
}