/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode *root)
{

    if (root == NULL)
        return 0;
    int r = maxDepth(root->right);
    int l = maxDepth(root->left);
    if (l > r)
        return l + 1;
    else
        return r + 1;
}