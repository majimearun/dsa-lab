#include <stdio.h>

int find_grps(int arr[], int n, int k, int thresh_avg)
{
    int start = 0;
    int count = 0;
    while (start <= n - k)
    {
        int sum = 0;
        for (int i = start; i < start + k; i++)
        {
            sum += arr[i];
        }
        if (sum / k >= thresh_avg)
        {
            count++;
        }
        start += 1;
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
    int grps = find_grps(arr, n, k, thresh_avg);
    printf("%d\n", grps);
    return 0;
}