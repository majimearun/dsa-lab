#include <stdio.h>
#include <stdlib.h>

int max(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int find_minimum_unfairness(int buckets[], int n_buckets, int curr_split[], int ppl, int curr_bucket, int curr_min)
{
    if (curr_bucket == n_buckets)
    {
        if (max(curr_split, ppl) < curr_min)
        {
            curr_min = max(curr_split, ppl);
        }
        return curr_min;
    }
    for (int i = 0; i < ppl; i++)
    {

        curr_split[i] += buckets[curr_bucket];
        curr_min = find_minimum_unfairness(buckets, n_buckets, curr_split, ppl, curr_bucket + 1, curr_min);
        curr_split[i] -= buckets[curr_bucket];
    }
    return curr_min;
}

int main()
{
    int n_buckets, ppl;
    scanf("%d %d", &n_buckets, &ppl);
    int buckets[n_buckets];
    for (int i = 0; i < n_buckets; i++)
    {
        scanf("%d", &buckets[i]);
    }
    int split[ppl];
    for (int i = 0; i < ppl; i++)
    {
        split[i] = 0;
    }
    printf("%d\n", find_minimum_unfairness(buckets, n_buckets, split, ppl, 0, 9999999));
    return 0;
}