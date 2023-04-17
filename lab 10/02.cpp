#include <bits/stdc++.h>

using namespace std;

bool search(vector<vector<int>> matrix, int m, int n, int i, int j, int elem)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return false;

    else
    {
        if (matrix[i][j] == elem)
            return true;
        else if (matrix[i][j] > elem)
            return false;
        else
        {
            bool found = search(matrix, m, n, i + 1, j, elem);
            if (found)
                return true;
            else
                return search(matrix, m, n, i, j + 1, elem);
        }
    }
}

int main()
{
    int m, n, k;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    cin >> k;
    bool found = search(matrix, m, n, 0, 0, k);
    if (found)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}