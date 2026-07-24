bool canConstruct(char *ransomNote, char *magazine)
{
    int a[26] = {0};
    int b[26] = {0};
    int max;
    if (strlen(magazine) < strlen(ransomNote))
        return 0;
    else
        max = strlen(magazine);
    for (int i = 0; i < max; i++)
    {
        b[magazine[i] - 'a']++;
        if (i < strlen(ransomNote))
            b[ransomNote[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (b[i] < 0)
            return 0;
    return 1;
}