#include <iostream>

using namespace std;

int linear_search(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int find_closest_common_ancestor(int *arr, int n, int i, int j)
{
    while (i != j)
    {
        if (i > j)
        {
            i = (i - 1) / 2;
        }
        else
        {
            j = (j - 1) / 2;
        }
    }
    return i;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int *arr = new int[n];
    for (int k = 0; k < n; k++)
    {
        cin >> arr[k];
    }
    int i = linear_search(arr, n, a);
    int j = linear_search(arr, n, b);
    cout << arr[find_closest_common_ancestor(arr, n, i, j)] << endl;
    return 0;
}