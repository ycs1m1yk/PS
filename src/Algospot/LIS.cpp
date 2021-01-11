#include <cstdio>
#include <cstring>
#include <algorithm>

/*
    종만북 8장
*/
using namespace std;
const int MAX = 1000;

int c, n;
int cache[MAX], S[MAX];

int lis(int start)
{
    int &ret = cache[start];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int next = start + 1; next < n; ++next)
    {
        if (S[start] < S[next])
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

        int answer = 0;
        for (int begin = 0; begin < n; ++begin)
            answer = max(answer, lis(begin));

        printf("%d\n", answer);
    }
}