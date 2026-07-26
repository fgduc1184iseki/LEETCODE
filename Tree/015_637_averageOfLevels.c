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
void average(struct TreeNode *root, int level, double *result, int *temp, int *returnsize)
{
    if (root == NULL)
        return;
    if (level + 1 > (*returnsize))
        *returnsize = level + 1;
    if (temp[level]==0)
        result[level] = root->val;
    else
        result[level] = (result[level]*temp[level] + root->val) / (temp[level] + 1);

    temp[level]++;
    

    average(root->left, level + 1, result, temp, returnsize);
    average(root->right, level + 1, result, temp, returnsize);
}
double *averageOfLevels(struct TreeNode *root, int *returnSize)
{
    if (root == NULL)
        return NULL;

    double *result = (double *)calloc(10000, sizeof(double));
    int *temp = (int *)calloc(10000, sizeof(int));
    int count = 0;
    average(root, 0, result, temp, &count);
    result[0] = root->val;
    *returnSize = count;

    return result;
}