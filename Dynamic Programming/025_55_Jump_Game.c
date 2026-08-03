bool canJump(int *nums, int numsSize)
{
    if (numsSize == 1)
        return 1;
    int tam = 0;
    for (int i = 0; i < numsSize - 1;)
    {
        if (nums[i] == 0)
            return 0;
        int max = -1;
        for (int j = 1; j <= nums[i]; j++)
        {
            if (i + j >= numsSize - 1)
                return 1;
            if (j + nums[i + j] > max &&nums[i+j]!=0)
            {
                max = j + nums[i + j];
                tam = j;
            }
        }
        if(tam==0)
        return 0;
        i = i + tam;
    }
    return 0;
}