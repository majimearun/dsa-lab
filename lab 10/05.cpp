#include <bits/stdc++.h>

using namespace std;

int max_nesting(vector<pair<int, int>> russian_dolls)
{
    int n = russian_dolls.size();
    vector<int> dp(n, 1);
    sort(russian_dolls.begin(), russian_dolls.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (russian_dolls[i].first > russian_dolls[j].first && russian_dolls[i].second > russian_dolls[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<pair<int, int>> russian_dolls;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w, h;
        cin >> w >> h;
        russian_dolls.push_back(make_pair(w, h));
    }

    cout << max_nesting(russian_dolls) << endl;

    return 0;
}