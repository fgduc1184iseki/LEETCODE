
bool isAnagram(char *s, char *t)
{
    int b[26] = {0};
    for (int i = 0; i < strlen(s); i++)
        b[s[i] - 'a']++;
    for (int i = 0; i < strlen(t); i++)
        b[t[i] - 'a']--;
    for (int i = 0; i < 26; i++)
        if (b[i] != 0)
            return 0;
    return 1;
}