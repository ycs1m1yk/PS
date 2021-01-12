#include <cstdio>
#include <cstring>

using namespace std;
const int MAX = 1000;

#define MAX(a, b) ((((a) > (b)) ? (a) : (b)))

int N, S[MAX + 1], cache[MAX];

int lis(int start)
{
    int &ret = cache[start + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int next = start + 1; next < N; ++next)
    {
        if (start == -1 || S[start] < S[next])
        {
            ret = MAX(ret, lis(next)+1);
        }
    }

    return ret;
}

int main()
{
    scanf("%d", &N);
    memset(S, -1, sizeof(S));
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &S[i]);
        S[i] *= -1;
    }

    printf("%d", lis(-1)-1);
}
