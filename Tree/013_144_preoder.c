/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorder(struct TreeNode *root, int *result, int *count)
{
    if (root == NULL)
        return;
    result[*count] = root->val;
    (*count)++;
    preorder(root->left, result, count);
    preorder(root->right, result, count);
}
int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *result = (int *)malloc(1000 * sizeof(int));
    int count = 0;
    preorder(root, result, &count);
    *returnSize = count;
    return result;
}