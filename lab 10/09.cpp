#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int sum1 = 0, sum2 = 0;
    priority_queue<int> pq1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq1.push(x);
        sum1 += x;
    }
    priority_queue<int> pq2;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        pq2.push(x);
        sum2 += x;
    }
    if (sum1 == sum2)
    {
        cout << "YES" << endl;
        return 0;
    }
    else
    {
        priority_queue<int> *larger, *smaller;
        int larger_sum, smaller_sum, ls, ss;
        larger = (sum1 > sum2) ? &pq1 : &pq2;
        ls = larger_sum = (sum1 > sum2) ? sum1 : sum2;
        smaller = (sum1 > sum2) ? &pq2 : &pq1;
        ss = smaller_sum = (sum1 > sum2) ? sum2 : sum1;
        while (!larger->empty() && !smaller->empty())
        {
            if (larger->top() > smaller->top())
            {
                ss += larger->top() - smaller->top();
                ls -= larger->top() - smaller->top();
                if (ss == ls)
                {
                    cout << "YES" << endl;
                    return 0;
                }
                else
                {
                    larger->pop();
                }
            }
            else
            {
                smaller->pop();
            }
            ls = larger_sum;
            ss = smaller_sum;
        }
    }
    cout << "NO" << endl;
    return 0;
}