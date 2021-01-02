#include <cstdio>
#include <cstring>

const int MAX = 91;

int n;
long long cache[MAX][2];

long long solve(int len, int n)
{
    if (len == 1)
    {
        if (n == 0)
            return 0;
        else
            return 1;
    }

    long long &ret = cache[len][n];
    if (ret != -1)
        return ret;

    ret = solve(len - 1, 0);
    if (n == 0)
        ret += solve(len - 1, 1);

    return ret;
}

int main()
{
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));

    long long result = solve(n, 0) + solve(n, 1);
    printf("%lld", result);
}