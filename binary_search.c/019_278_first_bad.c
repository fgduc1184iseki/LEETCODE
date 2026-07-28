// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
int binary(int l, int r)
{
    if (l == r)
        return l;

    int mid = l + (r - l) / 2;

    if (isBadVersion(mid))
        return binary(l, mid);
    else
        return binary(mid + 1, r);
}

int firstBadVersion(int n)
{
    return binary(1, n);
}
