bool isSubsequence(char *s, char *t)
{
    int i = 0, j = 0;

    if (strlen(s) == 0)
        return 1;
    if (strlen(s) > strlen(t))
        return 0;
    while (i < strlen(s) && j < strlen(t))
    {
        if (s[i] == t[j])
        {

            i++;
        }
        j++;
    }

    if (i == strlen(s) && j < strlen(t))
        return 1;
    else if (i == strlen(s) && s[i] == t[j])
    {
        return 1;
    }
    return 0;
}