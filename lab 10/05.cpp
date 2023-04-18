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
    for (int i = 0; i < n; i++)
    {
        cout << russian_dolls[i].first << " " << russian_dolls[i].second << endl;
    }
    return 0;
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