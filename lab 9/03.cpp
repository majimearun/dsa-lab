#include <iostream>
#include <stack>

using namespace std;

int sum_subarray_ranges(int *arr, int n)
{
    int max_sum = 0, min_sum = 0;

    stack<int> min_calc, max_calc;

    for (int i = 0; i <= n; i++)
    {
        while (!min_calc.empty() && (i == n || arr[min_calc.top()] > arr[i]))
        {
            int elem = min_calc.top();
            min_calc.pop();
            int prev_smaller = min_calc.empty() ? -1 : min_calc.top();
            min_sum += arr[elem] * (elem - prev_smaller) * (i - elem);
        }
        min_calc.push(i);
    }

    for (int i = 0; i <= n; i++)
    {
        while (!max_calc.empty() && (i == n || arr[max_calc.top()] < arr[i]))
        {
            int elem = max_calc.top();
            max_calc.pop();
            int prev_larger = max_calc.empty() ? -1 : max_calc.top();
            max_sum += arr[elem] * (elem - prev_larger) * (i - elem);
        }
        max_calc.push(i);
    }

    return max_sum - min_sum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    std::cout << sum_subarray_ranges(arr, n) << endl;
    return 0;
}