long long C(int n, int k) {
    if (k > n - k) k = n - k;

    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;
    }
    return res;
}

int uniquePaths(int m, int n) {
    return (int)C(m + n - 2, m - 1);
}
