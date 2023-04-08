// Explanation
// https://leetcode.com/problems/plates-between-candles/solutions/1586720/intuition-explained-prefix-sum-and-binary-search-c-clean-code/

#include <bits/stdc++.h>

using namespace std;

vector<int> plates_between_candles(string s, vector<vector<int>> &queries)
{

    int n = s.size();

    vector<int> next_candle(n, n), prev_candle(n, -1), prefix_sum(n, 0);

    for (int i = 0; i < n; i++)
    {

        prev_candle[i] = (s[i] == '*') ? ((i == 0) ? prev_candle[i] : prev_candle[i - 1]) : i;
        next_candle[n - i - 1] =
            (s[n - i - 1] == '*') ? ((i == 0) ? next_candle[n - i - 1] : next_candle[n - i]) : n - i - 1;

        prefix_sum[i] = (i == 0) ? (s[i] == '*') : prefix_sum[i - 1] + (s[i] == '*');
    }

    vector<int> answer;

    for (auto &query : queries)
    {

        int start = next_candle[query[0]] > query[1] ? 0 : next_candle[query[0]];
        int end = prev_candle[query[1]] < query[0] ? 0 : prev_candle[query[1]];

        answer.push_back(prefix_sum[end] - prefix_sum[start]);
    }

    return answer;
}

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> queries;
    for (int i = 0; i < q; i++)
    {
        int start, end;
        cin >> start >> end;
        queries.push_back({start, end});
    }

    auto answers = plates_between_candles(s, queries);

    for (auto v : answers)
    {
        cout << v << endl;
    }
}