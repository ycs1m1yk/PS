#include <cstdio>
#include <cstring>

const int MAX = 1001;
const int DIVISOR = 10007;

int n;
int cache[MAX][10];

int solve(int len, int n)
{
    if (len == 1)
    {
        return 1;
    }

    int &ret = cache[len][n];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = n; i >= 0; i--)
    {
        ret += solve(len - 1, i);
        ret %= DIVISOR;
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