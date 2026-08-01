void moveZeroes(int *nums, int numsSize)
{
    int f = 0, s = 0;

    while (f < numsSize)
    {

        if (nums[f] != 0 && nums[s] == 0)
        {
            int temp = nums[f];
            nums[f] = nums[s];
            nums[s] = temp;
            s++;
            f++;
        }
        else if (nums[s] == 0)
            f++;
        else if(f==s)
        {
            f++;
            s++;
        }
    }
}