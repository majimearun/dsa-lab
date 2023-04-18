#include <iostream>
#include <queue>

// wrong

using namespace std;

int main()
{
    int n, diff, elem, min = 9999999;
    priority_queue<int> q1;
    priority_queue<int> q2;
    cin >> n >> diff;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        q1.push(elem);
        if (elem < min)
        {
            min = elem;
        }
    }
    int required = min + diff;
    while (!q1.empty() && q1.top() >= required)
    {
        q2.push(q1.top());
        q1.pop();
    }
    int count = 0;
    while (!q1.empty() && !q2.empty())
    {
        if (q2.top() - q1.top() >= diff)
        {
            cout << q1.top() << " " << q2.top() << endl;
            count++;
            q2.pop();
        }
        q1.pop();
    }
    cout << count << endl;
}