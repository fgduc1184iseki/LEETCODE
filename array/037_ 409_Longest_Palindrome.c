int longestPalindrome(char *s)
{
    int b[52] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            b[s[i] - 'a']++;
        if (s[i] <= 'Z' && s[i] >= 'A')
            b[s[i] - 'A' + 26]++;
    }
    int sum = 0;
    int khoa = 0;
    for (int i = 0; i < 52; i++)
    {
        sum = sum + (b[i] / 2) * 2;
        if (!khoa && b[i] % 2 == 1)
            khoa = 1;
    }
    return khoa+sum;
}