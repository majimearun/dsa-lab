#include <bits/stdc++.h>

using namespace std;

int n_platforms(vector<pair<int, int>> trains, int n)
{
    sort(trains.begin(), trains.end());

    priority_queue<int, vector<int>, greater<int>> p;

    int count = 1;

    p.push(trains.at(0).second);

    for (int i = 1; i < n; i++)
    {

        if (p.top() >= trains.at(i).first)
        {
            count++;
        }
        else
        {
            p.pop();
        }
        p.push(trains.at(i).second);
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    int arr, dep;
    vector<pair<int, int>> trains;
    for (int i = 0; i < n; i++)
    {
        cin >> arr >> dep;
        trains.push_back({arr, dep});
    }
    cout << n_platforms(trains, n) << endl;
    return 0;
}