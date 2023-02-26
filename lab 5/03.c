#include <stdio.h>
#include <stdlib.h>

int update_freq(int freq[], int k, char alpha, int adding)
{
    if (adding)
    {
        int i = (int)(alpha - 97);
        if (i < k)
        {
            freq[i]--;
        }
    }
    else
    {
        int i = (int)(alpha - 97);
        if (i < k)
        {
            freq[i]++;
        }
    }
}
int check(int freq[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (freq[i] > 0)
        {
            return 0;
        }
    }
    return 1;
}

int n_window(int n, int k, char *string)
{
    int count = 0;
    int l = 0;
    int r = 0;
    int freq[k];
    for (int i = 0; i < k; i++)
    {

        freq[i] = 1;
    }
    update_freq(freq, k, string[0], 1);
    while (r < n)
    {
        if (check(freq, k))
        {
            while (check(freq, k))
            {
                count += n - r;
                update_freq(freq, k, string[l], 0);
                l++;
            }
        }
        else
        {
            r++;
            update_freq(freq, k, string[r], 1);
        }
    }
    return count;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    char string[n];
    scanf("%s", string);
    printf("%d\n", n_window(n, k, string));
}