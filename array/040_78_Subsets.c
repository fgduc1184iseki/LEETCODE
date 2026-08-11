/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void solve(int *num, int *returnSize, int **returnColumnSizes,
           int k, int **result, int *temp, int max)
{
    if (k == 0)
    {
        result[(*returnSize)] = malloc(max * sizeof(int));
        int m = 0;

        for (int i = 0; i < max; i++)
            if (temp[i] == 1)
            {
                result[(*returnSize)][m] = num[i];
                m++;
            }
        (*returnColumnSizes)[(*returnSize)] = m;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        temp[k - 1] = i;
        solve(num, returnSize, returnColumnSizes, k - 1, result, temp, max);
    }
}
int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;

    int total = 1 << numsSize;

    int **result = malloc(total * sizeof(int *));
    *returnColumnSizes = malloc(total * sizeof(int));

    int *temp = malloc(numsSize * sizeof(int));

    solve(nums, returnSize, returnColumnSizes,
          numsSize, result, temp, numsSize);

    free(temp);

    return result;
}