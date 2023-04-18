#include <bits/stdc++.h>

using namespace std;

int find_kth_smallest(vector<vector<int>> &v, int k)
{
    int n = v.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<>> min_heap;
    for (int i = 0; i < n; i++)
    {
        min_heap.push({v[i][0], i, 0});
    }
    int ans{0};
    for (int i = 0; i < k; i++)
    {
        auto top = min_heap.top();
        min_heap.pop();
        ans = top[0];
        int row = top[1];
        int col = top[2];
        if (col + 1 < n)
        {
            min_heap.push({v[row][col + 1], row, col + 1});
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << find_kth_smallest(v, k) << endl;

    return 0;
}