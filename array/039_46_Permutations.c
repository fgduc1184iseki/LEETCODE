#include <stdlib.h>

void com(int *nums, int n, int pos, int *m,
         int **result, int *current, int *used)
{
    if (pos == n)
    {
        result[*m] = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            result[*m][i] = current[i];

        (*m)++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            current[pos] = nums[i];
            used[i] = 1;

            com(nums, n, pos + 1, m, result, current, used);

            used[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize,
              int* returnSize, int** returnColumnSizes)
{
    int max = 1;

    for (int i = 1; i <= numsSize; i++)
        max *= i;

    int **result = malloc(max * sizeof(int *));
    int *current = malloc(numsSize * sizeof(int));
    int *used = calloc(numsSize, sizeof(int));

    int m = 0;

    com(nums, numsSize, 0, &m,
        result, current, used);

    *returnSize = m;

    *returnColumnSizes = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        (*returnColumnSizes)[i] = numsSize;

    free(current);
    free(used);

    return result;
}