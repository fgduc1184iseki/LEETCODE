int search(int *nums, int numsSize, int target)
{
    int l = 0, r = numsSize - 1;
    while (l <= r)
    {
        if (nums[(l + r) / 2] == target)
            return (l + r) / 2;
        else if (target > nums[(l + r) / 2])
        {
            l = (l + r) / 2 + 1;
        }
        else if (target < nums[(l + r) / 2])
        {
            r = (r + l) / 2 - 1;
        }
    }
    return -1;
}