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
void postorder(struct TreeNode *root, int *result, int *count)
{
    if (root == NULL)
        return;
    postorder(root->left, result, count);
    postorder(root->right, result, count);
    result[*count] = root->val;
    (*count)++;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *result = (int *)malloc(1000 * sizeof(int));
    int count =0;
    postorder(root,result,&count);
    *returnSize=count;
    return result;
}