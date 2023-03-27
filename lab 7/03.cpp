#include <iostream>

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

int countFreedomNodes(TreeNode *root, int targetSum, int currentSum)
{
    if (!root)
    {
        return 0;
    }
    currentSum += root->val;
    if (!root->left && !root->right && currentSum == targetSum)
    {
        return 1;
    }
    return countFreedomNodes(root->left, targetSum, currentSum) + countFreedomNodes(root->right, targetSum, currentSum);
}

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

int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    TreeNode *root = createTree(arr, n, 0);

    cout << countFreedomNodes(root, sum, 0) << endl;
}
