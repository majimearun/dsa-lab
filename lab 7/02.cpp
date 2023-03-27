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

TreeNode *buildTreeHelper(int *preorder, int *inorder, int n, int preStart, int inStart, int inEnd)
{
    if (preStart >= n || inStart > inEnd)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[preStart]);

    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == root->val)
        {
            inIndex = i;
            break;
        }
    }

    root->left = buildTreeHelper(preorder, inorder, n, preStart + 1, inStart, inIndex - 1);
    root->right = buildTreeHelper(preorder, inorder, n, preStart + 1 + (inIndex - inStart), inIndex + 1, inEnd);

    return root;
}

TreeNode *buildTree(int *preorder, int *inorder, int n)
{
    return buildTreeHelper(preorder, inorder, n, 0, 0, n - 1);
}

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    int n;
    cin >> n;

    int preorder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    int inorder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    TreeNode *root = buildTree(preorder, inorder, n);

    printTree(root);
    cout << endl;
}