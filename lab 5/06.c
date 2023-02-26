#include <stdio.h>
#include <stdlib.h>

int array_xor(int arr[], int n)
{
    int x = arr[0];
    for (int i = 1; i < n; i++)
    {
        x = x ^ arr[i];
    }
    return x;
}

int fancy_xor(int a[], int n, int b[], int m)
{
    int xor1 = array_xor(a, n);
    int xor2 = array_xor(b, m);
    xor1 = m % 2 ? xor1 : 0;
    xor2 = n % 2 ? xor2 : 0;
    return xor1 ^ xor2;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    printf("%d\n", fancy_xor(arr1, n, arr2, m));
}