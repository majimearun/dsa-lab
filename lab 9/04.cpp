#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    map<long long, int> count;
    count[0] = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans += count[sum - k * (i + 1)];
        count[sum - k * (i + 1)]++;
    }
    cout << ans << endl;
    return 0;
}
