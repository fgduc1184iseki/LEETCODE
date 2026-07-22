/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool sym(struct TreeNode *root, struct TreeNode *head)
{
    if (head != NULL && root != NULL)
    {
        if (root->val == head->val)
        {
            if (root->left == NULL && head->right == NULL && root->right == NULL && head->left == NULL)
            {
                return 1;
            }
            if (root->left == NULL && root->right != NULL && head->right == NULL && head->left != NULL)
            {
                return sym(root->right, head->left);
            }
            else if (root->right == NULL && root->left != NULL && head->left == NULL && head->right != NULL)
            {
                return sym(root->left, head->right);
            }
            else if (root->left != NULL && root->right != NULL && head->right != NULL && head->left != NULL)
            {
                if (sym(root->left, head->right) == 1 && sym(root->right, head->left) == 1)
                    return 1;
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }

    return 0;
}
bool isSymmetric(struct TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return 1;
    return sym(root->left, root->right);
}