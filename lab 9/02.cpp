#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int curr_candle = -1;
    stack<int> plates_waiting;
    // candle before, candle after
    vector<vector<int>> search;
    for (int i = 0; i < n; i++)
    {
        search.push_back({-1, -1});
    }
    vector<int> prefix_sum(n, 0);
    int count = 0;
    char curr;

    for (int i = 0; i < n; i++)
    {
        cin >> curr;
        if (curr == '|')
        {
            curr_candle = i;
            while (!plates_waiting.empty())
            {
                search.at(plates_waiting.top()).at(1) = curr_candle;
                plates_waiting.pop();
            }
            search.at(i) = {i, i};
        }
        else if (curr == '*')
        {
            search.at(i).at(0) = curr_candle;
            plates_waiting.push(i);
            count++;
        }
        prefix_sum.at(i) = count;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << search.at(i).at(0) << " " << search.at(i).at(1) << " " << prefix_sum.at(i) << endl;
    // }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l = search.at(l).at(1);
        r = search.at(r).at(0);
        if (l == -1 || r == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << prefix_sum.at(r) - prefix_sum.at(l) << endl;
        }
    }
}