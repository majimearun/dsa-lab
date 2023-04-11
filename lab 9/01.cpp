#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    vector<pii> bottles;
    vector<int> prefix_sum;
    int count = 0, prefix = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        if (elem >= 0)
        {
            count++;
            sum += elem;
            prefix += elem;
        }
        else
        {
            bottles.push_back({i, elem});
        }
        prefix_sum.push_back(prefix);
    }

    priority_queue<pii> pq(bottles.begin(), bottles.end());

    while (!pq.empty() && sum >= 0)
    {
        if (sum + pq.top().second >= 0)
        {
            if (prefix_sum.at(pq.top().first) + pq.top().second >= 0)
            {
                count++;
                sum += pq.top().second;
            }
        }
        pq.pop();
    }

    cout << count << endl;
    return 0;
}