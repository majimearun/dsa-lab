#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int get_gas[n];
    int use_gas[n];
    for (int i = 0; i < n; i++)
    {
        cin >> get_gas[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> use_gas[i];
    }
    int start = 0;
    int total_gas_got = 0;
    int total_gas_used = 0;
    int curr_gas = 0;
    for (int i = 0; i < n; i++)
    {
        total_gas_got += get_gas[i];
        total_gas_used += use_gas[i];
        curr_gas += get_gas[i] - use_gas[i];
        if (curr_gas < 0)
        {
            start = i + 1;
            curr_gas = 0;
        }
    }
    if (total_gas_got >= total_gas_used)
        cout << start << endl;
    else
        cout << -1 << endl;
    return 0;
}