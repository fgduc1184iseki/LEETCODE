int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int vitri = -1;

    int max = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            if (vitri == -1)
            {
                max = i - 0 ;
                vitri = i;
            }
            else
            {
                if (i - vitri - 1 > max)
                    max = i - vitri - 1;
                vitri = i;
            }
        }
    }
    if (vitri == -1)
        return numsSize;
    else if (numsSize - vitri - 1 > max)
    {
        return numsSize - vitri - 1;
    }

    else
        return max;
}