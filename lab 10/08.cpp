#include <bits/stdc++.h>

using namespace std;

void sort_a_wrt_relative_order_in_b(vector<int> &a, vector<int> &b)
{

    unordered_map<int, int> m;
    for (int i = 0; i < b.size(); i++)
        m[b[i]] = i;
    for (int i = 0; i < a.size(); i++)
    {
        if (m.find(a[i]) == m.end())
            m[a[i]] = b.size() + a[i];
    }
    sort(a.begin(), a.end(), [&](int x, int y) { return m[x] < m[y]; });
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort_a_wrt_relative_order_in_b(a, b);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}