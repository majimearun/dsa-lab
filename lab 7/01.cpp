#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    int n, m, elem, cost = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        pq.push(elem);
    }
    for (int i = 0; i < m; i++)
    {
        elem = pq.top();
        pq.pop();
        pq.push(elem / 2);
    }
    while (!pq.empty())
    {
        cost += pq.top();
        pq.pop();
    }
    cout << cost << endl;
    return 0;
}