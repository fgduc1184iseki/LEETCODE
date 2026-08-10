#include <stdlib.h>

void com(int n, int pos, int k, int start, int *m, int **result, int *current)
{
    if (pos == k)
    {
        result[*m] = malloc(k * sizeof(int));

        for (int i = 0; i < k; i++)
            result[*m][i] = current[i];

        (*m)++;
        return;
    }

    for (int i = start; i <= n; i++)
    {
        current[pos] = i;

        com(n, pos + 1, k, i + 1, m, result, current);
    }
}

int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    int max = 184756;

    int **result = malloc(max * sizeof(int *));
    *returnColumnSizes = malloc(max * sizeof(int));

    int *current = malloc(k * sizeof(int));

    int m = 0;

    com(n, 0, k, 1, &m, result, current);

    *returnSize = m;

    for (int i = 0; i < m; i++)
        (*returnColumnSizes)[i] = k;

    free(current);

    return result;
}