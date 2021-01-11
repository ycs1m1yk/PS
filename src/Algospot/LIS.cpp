#include <cstdio>
#include <cstring>
#include <algorithm>

/*
    종만북 8장
*/
using namespace std;
const int MAX = 1000;

int c, n;
int cache[MAX + 1], S[MAX];

int lis(int start)
{
    int &ret = cache[start + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int next = start + 1; next < n; ++next)
    {
        if (start == -1 || S[start] < S[next])
        {
            ret = max(ret, lis(next) + 1);
        }
    }

    return ret;
}

int main()
{
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &n);
        memset(S, -1, sizeof(S));
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < n; ++i)
            scanf("%d", &S[i]);
        // S[-1] = -∞ 라고 가정하고 S[0]부터 순회하도록
        printf("%d\n", lis(-1) - 1);
    }
}