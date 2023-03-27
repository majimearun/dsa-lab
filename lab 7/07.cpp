#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k, elem;
    cin >> n >> k;
    int satisfaction = 0;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        q.push(elem);
    }
    for (int i = 0; i < k; i++)
    {
        elem = q.top();
        satisfaction += (elem + 1) / 2;
        elem -= (elem + 1) / 2;
        q.pop();
        q.push(elem);
    }
    cout << satisfaction << endl;
    return 0;
}