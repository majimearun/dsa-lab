#include <iostream>
#include <stack>

using namespace std;

class StackObj
{
  public:
    int elem;
    int index;
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<StackObj> stocks;
    int soln[n];
    for (int i = 0; i < n; i++)
    {
        soln[i] = 1;
    }
    int i = 0;
    while (i <= n - 1)
    {
        auto stackObj = new StackObj;
        stackObj->elem = arr[i];
        stackObj->index = i;
        if (stocks.empty() || arr[i] < stocks.top().elem)
        {
            stocks.push(*stackObj);
        }
        else
        {
            int curr_index = 0;
            while (!stocks.empty() && arr[i] >= stocks.top().elem)
            {
                curr_index = i - stocks.top().index + soln[stocks.top().index];
                stocks.pop();
            }
            soln[i] = curr_index;
            stocks.push(*stackObj);
        }
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << soln[i] << " ";
    }
    cout << endl;
}