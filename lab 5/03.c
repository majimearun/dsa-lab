#include <stdio.h>
#include <stdlib.h>

int check(char string[], int n, int l, int r, int k)
{
    char required[k];
    for (int i = 0; i < k; i++)
    {
        required[i] = (char)(97 + i);
    }
    int count = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (string[i] == required[j])
            {
                required[j] = '0';
                count++;
                break;
            }
        }
        if (count == k)
        {
            return 1;
        }
    }
    if (count == k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int n_window(int n, int k, char *alphabet)
{
    int count = 0;
    int l = 0;
    int r = 0;
    while (r < n)
    {
        if (check(alphabet, n, l, r, k))
        {
            while (check(alphabet, n, l, r, k))
            {
                count += n - r;
                l++;
            }
        }
        else
        {
            r++;
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