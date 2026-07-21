/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (q == NULL && p == NULL)
        return 1;
    else if (q == NULL || p == NULL)
    {
        return 0;
    }

    if ((p->val != q->val))
        return 0;
    if ((p->left == NULL && q->left == NULL) && (p->right == NULL && q->right == NULL))
        return 1;
    if (isSameTree(q->left, p->left) == 0 || isSameTree(q->right, p->right) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}