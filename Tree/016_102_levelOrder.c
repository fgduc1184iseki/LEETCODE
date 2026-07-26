void order(struct TreeNode *root, int **result, int *temp, int level,int *max)
{
    if (root == NULL)
        return;
    if((*max)<level+1)
    (*max)=level+1;
    if (result[level] == NULL)
    {
        result[level] = (int *)malloc(2000 * sizeof(int));
    }
    result[level][temp[level]] = root->val;
    temp[level]++;
    order(root->left, result, temp, level + 1,max);
    order(root->right, result, temp, level + 1,max);
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{

    *returnSize = 0;
    if (root == NULL)
    {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int **result = (int **)calloc(2000, sizeof(int *));

    *returnColumnSizes = (int *)calloc(2000, sizeof(int));
    order(root, result, *returnColumnSizes, 0,returnSize);
    return result;
}