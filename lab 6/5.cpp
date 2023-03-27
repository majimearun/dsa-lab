#include <deque>
#include <iostream>
using namespace std;

void printKMax(int arr[], int N, int K)
{
    // index queue
    std::deque<int> Qi(K);

    int i;
    //  insert first k elements, but keep the front of the queue as the index of largest till k
    for (i = 0; i < K; ++i)
    {

        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])

            Qi.pop_back();

        Qi.push_back(i);
    }

    // for all elements henceforth
    // print front
    // remove element(s) from prvs window
    // remove all smaller elements in queue when pushing a new element
    for (; i < N; ++i)
    {

        cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && Qi.front() <= i - K)
            Qi.pop_front();
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    cout << arr[Qi.front()];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int j = 0; j < n; j++)
        cin >> arr[j];

    printKMax(arr, n, k);
    return 0;
}