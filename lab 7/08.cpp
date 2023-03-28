#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
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

TreeNode *delete_if_not_in_range(TreeNode *root, int l, int r)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val < l)
    {
        return delete_if_not_in_range(root->right, l, r);
    }
    if (root->val > r)
    {
        return delete_if_not_in_range(root->left, l, r);
    }
    root->left = delete_if_not_in_range(root->left, l, r);
    root->right = delete_if_not_in_range(root->right, l, r);
    return root;
}

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    printTree(root->left);
    printTree(root->right);
    cout << root->val << " ";
}

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    auto root = createTree(arr, n, 0);
    auto bst = delete_if_not_in_range(root, l, r);

    printTree(bst);
    cout << endl;
    return 0;
}