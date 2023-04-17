#include <bits/stdc++.h>

using namespace std;

void flip(int arr[], int i)
{
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int find_max(int arr[], int n)
{
    int max = INT_MIN, max_index;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
    }
    return max_index;
}

void pancake_sort(int arr[], int n, vector<int> &flips)
{
    for (int curr_size = n; curr_size > 1; curr_size--)
    {
        int max_index = find_max(arr, curr_size);
        if (max_index != curr_size - 1)
        {
            if (max_index != 0)
                flips.push_back(max_index + 1);
            flip(arr, max_index);
            flips.push_back(curr_size);
            flip(arr, curr_size - 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> flips;

    pancake_sort(arr, n, flips);

    cout << flips.size() << endl;
    for (int i = 0; i < flips.size(); i++)
        cout << flips[i] << " ";
    cout << endl;
    return 0;
}