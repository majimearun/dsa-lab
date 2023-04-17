#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &A, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid + 1;
    int count = 0;
    while (i <= mid && j <= right)
    {
        if (A[i] > A[j])
        {
            temp.push_back(A[j++]);
            count += mid - i + 1;
        }
        else
        {
            temp.push_back(A[i++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(A[i++]);
    }
    while (j <= right)
    {
        temp.push_back(A[j++]);
    }
    for (int i = left, j = 0; i <= right; i++, j++)
    {
        A[i] = temp[j];
    }
    return count;
}

int merge_sort(vector<int> &A, int left, int right)
{
    int count = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        count += merge_sort(A, left, mid);
        count += merge_sort(A, mid + 1, right);
        count += merge(A, left, mid, right);
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int count = merge_sort(A, 0, n - 1);
    cout << count << endl;
    return 0;
}
