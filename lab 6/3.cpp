#include <iostream>
#include <stack>

using namespace std;

int get_max(int *histogram, int n)
{
    stack<int> bars;

    int max_area = 0;
    int top;
    int area;
    int i = 0;
    while (i < n)
    {
        if (bars.empty() || histogram[bars.top()] <= histogram[i])
        {
            bars.push(i++);
        }
        else
        {
            top = bars.top();
            bars.pop();
            area = histogram[top] * (bars.empty() ? i : i - bars.top() - 1);
            if (max_area < area)
            {
                max_area = area;
            }
        }
    }
    while (!bars.empty())
    {
        top = bars.top();
        bars.pop();
        area = histogram[top] * (bars.empty() ? i : i - bars.top() - 1);
        if (max_area < area)
        {
            max_area = area;
        }
    }

    return max_area;
}

int main()
{
    int n;
    cin >> n;
    int histogram[n];
    for (int i = 0; i < n; i++)
    {
        cin >> histogram[i];
    }
    int max_area = get_max(histogram, n);
    cout << max_area << endl;
}