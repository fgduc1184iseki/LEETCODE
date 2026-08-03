int max3(int a, int b, int c)
{
    int max = a;

    if (b > max)
        max = b;

    if (c > max)
        max = c;

    return max;
}
int max2(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int rob(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0)
            ;
        else if (i == 1)
        {
            nums[i] = max2(nums[i], nums[i - 1]);
        }

        else if (i == 2)
        {
            nums[i] = max2(nums[i - 1], nums[i] + nums[i - 2]);
        }
        else
        {
            nums[i] = max3(nums[i - 1], nums[i - 2] + nums[i], nums[i - 3] + nums[i]);
        }
    }
    return nums[numsSize - 1];
}