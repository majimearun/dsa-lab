#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    int array;
    int index;
};

struct Compare
{
    bool operator()(Node a, Node b)
    {
        return a.data > b.data;
    }
};

typedef priority_queue<Node, vector<Node>, Compare> min_heap;

int main()
{
    int n;
    cin >> n;
    int **a = new int *[n];
    int sizes[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        sizes[i] = k;
        a[i] = new int[k];
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
        }
    }
    min_heap q;
    for (int i = 0; i < n; i++)
    {
        q.push({a[i][0], i, 0});
    }
    while (!q.empty())
    {
        Node node = q.top();
        q.pop();
        cout << node.data << " ";
        if (node.index + 1 < sizes[node.array])
        {
            q.push({a[node.array][node.index + 1], node.array, node.index + 1});
        }
    }
    cout << endl;
    return 0;
}