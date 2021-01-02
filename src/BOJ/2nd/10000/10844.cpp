#include <cstdio>
#include <cstring>

const int MAX = 101;
const int DIVISOR = 1000000000;

int n;
int cache[MAX][10];

int solve(int len, int n)
{
    if (len == 1)
    {
        if (n == 0)
            return 0;
        else
            return 1;
    }

    int &ret = cache[len][n];
    if (ret != -1)
        return ret;

    if (n == 0)
    {
        ret = solve(len - 1, 1);
    }
    else if (n == 9)
    {
        ret = solve(len - 1, 8);
    }
    else
    {
        ret = (solve(len - 1, n - 1) + solve(len - 1, n + 1)) % DIVISOR;
    }

    return ret;
}

int main()
{
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        result += solve(n, i);
        result %= DIVISOR;
    }
    printf("%d", result);
}