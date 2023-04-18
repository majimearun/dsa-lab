#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp1[x] = i;
        sum1 += x;
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        mp2[x] = i;
        sum2 += x;
    }

    if (sum1 == sum2)
    {
        cout << "YES" << endl;
    }
    else if ((sum1 + sum2) % 2 == 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        int req = abs((sum1 - sum2) / 2);
        auto larger = (sum1 > sum2) ? mp1 : mp2;
        auto smaller = (sum1 > sum2) ? mp2 : mp1;

        for (auto it = larger.begin(); it != larger.end(); it++)
        {
            if (smaller.find(it->first - req) != smaller.end())
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
}
