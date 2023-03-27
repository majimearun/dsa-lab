#include <iostream>

using namespace std;

void print_post_order(int *arr, int n, int i)
{
    if (i < n && arr[i] == -1)
    {
        print_post_order(arr, n, 2 * i + 1);
        print_post_order(arr, n, 2 * i + 2);
    }
    else if (i < n)
    {
        print_post_order(arr, n, 2 * i + 1);
        print_post_order(arr, n, 2 * i + 2);
        cout << arr[i] << " ";
    }
}

void delete_not_in_range(int *arr, int n, int i, int l, int r)
{
    if (arr[i] == -1)
    {
        return;
    }
    if (i < n)
    {
        delete_not_in_range(arr, n, 2 * i + 1, l, r);
        delete_not_in_range(arr, n, 2 * i + 2, l, r);
        if (arr[i] < l || arr[i] > r)
        {
            arr[i] = -1;
        }
    }
}

int find_first_index_not_minus_one(int *arr, int n, int i)
{
    if (i < n && arr[i] == -1)
    {
        return find_first_index_not_minus_one(arr, n, i + 1);
    }
    else
    {
        return i;
    }
}

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    delete_not_in_range(arr, n, 0, l, r);
    print_post_order(arr, n, find_first_index_not_minus_one(arr, n, 0));
    cout << endl;
    return 0;
}