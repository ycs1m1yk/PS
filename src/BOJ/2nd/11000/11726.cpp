#include <cstdio>
#include <cstring>

const int MAX = 1001;
const int DIVISOR = 10007;

int n;
int cache[MAX];

int solve(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    int &ret = cache[n];
    if (ret != -1)
        return ret;

    return ret = (solve(n - 2) + solve(n - 1)) % DIVISOR;
}

int main()
{
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));

    printf("%d", solve(n));
}