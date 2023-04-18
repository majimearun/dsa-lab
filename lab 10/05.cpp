#include <bits/stdc++.h>

using namespace std;

int max_nesting(vector<pair<int, int>> russian_dolls)
{
    int n = russian_dolls.size();
    sort(russian_dolls.begin(), russian_dolls.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    vector<int> dp;
    for (auto &doll : russian_dolls)
    {
        int height = doll.second;
        int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
        if (left == dp.size())
            dp.push_back(height);
        dp[left] = height;
    }
    return dp.size();
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