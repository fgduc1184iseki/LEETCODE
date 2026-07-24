bool isPalindrome(char *s)
{
    int l = 0;
    int r = strlen(s) - 1;
    int on = 0;
    char check;
    if (strlen(s) <= 1)
        return 1;
    while (l <= r)
    {
        if (on == 0)
        {
            if ((s[l] >= '0' && s[l] <= '9') || (s[l] <= 'z' && s[l] >= 'a'))
            {
                check = s[l];
                on = 1;
            }
            else if (s[l] <= 'Z' && s[l] >= 'A')
            {
                check = s[l] - 'A' + 'a';
                on = 1;
            }
            l++;
        }
        else
        {
            if ((s[r] >= '0' && s[r] <= '9') || (s[r] <= 'z' && s[r] >= 'a'))
            {
                if (check != s[r])
                    return 0;
                on = 0;
            }
            else if (s[r] <= 'Z' && s[r] >= 'A')
            {
                if (check != s[r] - 'A' + 'a')
                    return 0;
                on = 0;
            }
            r--;
        }
    }
    return true;
}