#include <bits/stdc++.h>

using namespace std;

float median_of_two_sorted_arrays(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    if (n > m)
        return median_of_two_sorted_arrays(arr2, arr1);

    int low = 0, high = n;

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n + m) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
}

int main()
{
    int n, m;
    vector<int> arr1, arr2;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr1.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        arr2.push_back(x);
    }
    float median = median_of_two_sorted_arrays(arr1, arr2);
    cout << median << endl;
    return 0;
}