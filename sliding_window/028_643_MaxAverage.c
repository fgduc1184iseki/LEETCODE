double findMaxAverage(int *nums, int numsSize, int k)
{
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum = sum + nums[i];
    }
    double aver = sum;
    double max = sum;
    for (int i = k; i < numsSize; i++)
    {
        sum = sum - nums[i - k] + nums[i];
        if (sum > max)
            max = sum;
    }
    return max / k;
}