#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> bottles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bottles[i];
    }

    priority_queue<int> pq(bottles.begin(), bottles.end());

    int count = 0, sum = 0;
    while (!pq.empty())
    {
        auto elem = pq.top();
        pq.pop();

        if (sum + elem >= 0)
        {
            sum += elem;
            count++;
        }
        else
        {
            while (!pq.empty())
            {
                elem = pq.top();
                pq.pop();
                if (sum + elem >= 0)
                {
                    sum += elem;
                    count++;
                    break;
                }
            }
            if (sum + elem < 0)
            {
                break;
            }
        }
    }

    cout << count << endl;
    return 0;
}