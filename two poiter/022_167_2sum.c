/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int j,i;
    int *result=(int*)malloc(2*sizeof(int));
    for (i = 1; i < numbersSize; i++)
    {
        if (numbers[i] + numbers[i - 1] >= target)
        {
            j = i - 1;
            while (j>=0&&numbers[i] + numbers[j] >= target)
            {
                if(numbers[i]+numbers[j]==target)
                break;
                j--;
            }
            if(j>=0&&numbers[i]+numbers[j]==target)
            break;
        }
    }
    result[0]=j+1;
    result[1]=i+1;
    *returnSize=2;
    return result;
}