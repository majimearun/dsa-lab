#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

TreeNode *createTree(int arr[], int n, int i)
{
    if (i >= n)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(arr[i]);
    root->left = arr[2 * i + 1] == -1 ? nullptr : createTree(arr, n, 2 * i + 1);
    root->right = arr[2 * i + 2] == -1 ? nullptr : createTree(arr, n, 2 * i + 2);
    return root;
}

int kthLargest(TreeNode *root, int k)
{
    int count = 0, elem = 0;
    stack<TreeNode *> stk;
    TreeNode *curr = root;
    while (curr != nullptr || !stk.empty())
    {
        while (curr != nullptr)
        {
            stk.push(curr);
            curr = curr->right;
        }
        curr = stk.top();
        stk.pop();
        elem = curr->val;
        count++;
        if (count == k)
        {
            return elem;
        }
        curr = curr->left;
    }
    return -1;
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
    int k;
    cin >> k;
    TreeNode *root = createTree(arr, n, 0);

    cout << kthLargest(root, k) << endl;
}
