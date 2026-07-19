bool isPalindrome(int x)
{
    if (x < 0)
        return 0;
    int n = -1;
    int temp = x;
    int b[11];
    while (temp != 0)
    {
        n=n+1;
        b[n] = temp % 10;
        temp = temp / 10;
    }
    for (int i = 0; i <= n; i++)
        if (b[i] != b[n - i])
            return 0;
    return 1;
}