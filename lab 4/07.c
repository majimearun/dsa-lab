#include <stdio.h>
#include <stdlib.h>

int get_max(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
        {
            max = array[i];
        }
    return max;
}

void count_sort(int array[], int n, int place)
{
    int output[n + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < n; i++)
    {
        if (((array[i] / place) % 10) > max)
        {
            max = array[i];
        }
    }
    int count[max + 1];

    for (int i = 0; i < max; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        array[i] = output[i];
    }
}

void radix_sort(int array[], int n)
{
    int max = get_max(array, n);

    for (int place = 1; max / place > 0; place *= 10)
    {
        count_sort(array, n, place);
        for (int i = 0; i < n; ++i)
        {
            printf("%d  ", array[i]);
        }
        printf("\n");
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
    radix_sort(arr, n);
    return 0;
}