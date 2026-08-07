#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int i = 0;
    int j = 0;

    while (i < sSize)
    {
        if (j == gSize)
            return j;
        if (s[i] >= g[j])
        {
            j++;
        }

        i++;
    }
    return j;
}