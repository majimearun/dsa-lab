#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> q1;
    priority_queue<int> q2;
    int n, k, elem;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        q1.push(elem);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        q2.push(elem);
    }
    int max1 = q1.top();
    int max2 = q2.top();
    cout << max1 + max2 << " ";
    q1.pop();
    q2.pop();
    for (int i = 0; i < k - 1; i++)
    {
        if (max1 + q2.top() > max2 + q1.top())
        {
            cout << max1 + q2.top() << " ";
            q2.pop();
        }
        else
        {
            cout << max2 + q1.top() << " ";
            q1.pop();
        }
    }
    cout << endl;
    return 0;
}