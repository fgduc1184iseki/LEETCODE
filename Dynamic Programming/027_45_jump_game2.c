int jump(int *nums, int numsSize)
{
  if (numsSize == 1)
    return 0;
  int buoc = 0;
  int tam = 1;
  for (int i = 0; i < numsSize-1;)
  {
    int max = -1;
    for (int j = 1; j <= nums[i]; j++)
    {

      if (i + j < numsSize-1)
      {
        if (nums[i + j] + j > max )
        {
          max = nums[i + j] + j;
          tam = j;
        }
      }
      else
        return buoc+1;
    }
    i = i + tam;
    buoc++;
  }
  return buoc;
}