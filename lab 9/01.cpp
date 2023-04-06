#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> bottles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bottles[i].first;
        bottles[i].second = i;
    }

    priority_queue<pair<int, int>> pq(bottles.begin(), bottles.end());

    int count = 0, sum = 0;
    while (!pq.empty())
    {
        auto elem = pq.top();
        pq.pop();

        if (sum + elem.first >= 0)
        {
            sum += elem.first;
            count++;
        }
        else
        {
            while (!pq.empty())
            {
                elem = pq.top();
                pq.pop();
                if (sum + elem.first >= 0)
                {
                    sum += elem.first;
                    count++;
                    break;
                }
            }
            if (sum + elem.first < 0)
            {
                break;
            }
        }
    }

    cout << count << endl;
    return 0;
}