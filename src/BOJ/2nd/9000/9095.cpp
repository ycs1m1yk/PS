#include <cstdio>
#include <cstring>

const int MAX = 11;

int T, n;
int cache[MAX];

int solve(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;

    int &ret = cache[n];
    if (ret != -1)
        return ret;

    return ret = solve(n - 3) + solve(n - 2) + solve(n - 1);
}

int main()
{
    scanf("%d", &T);
    memset(cache, -1, sizeof(cache));
    while (T--)
    {
        scanf("%d", &n);
        printf("%d", solve(n));
        if(T>0) printf("\n");
    }
}