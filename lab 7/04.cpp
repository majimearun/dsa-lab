#include <iostream>

using namespace std;

void fn(int arr[], int i, int n, int &sum)
{
    // static int sum = 0;

    if (arr[i] != -1 && i < n)
    {
        fn(arr, 2 * i + 2, n, sum);
        sum += arr[i];
        arr[i] = sum;
        fn(arr, 2 * i + 1, n, sum);
    }
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

    int i = 0;
    fn(arr, 0, n, i);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}