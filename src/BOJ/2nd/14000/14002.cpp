#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
const int LEN = 1000;

int N, S[LEN], C[LEN], cache[LEN + 1];

int lis(int start)
{
    int &ret = cache[start + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int nxt = start + 1; nxt < N; ++nxt)
    {
        if (start == -1 || S[start] < S[nxt])
        {
            ret=max(ret, lis(nxt)+1);
        }
    }

    return ret;
}

int main()
{
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));
    memset(S, -1, sizeof(S));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &S[i]);
    }

    int ans = lis(-1) - 1;
    printf("%d\n", ans);

    int begin=0;
    for (int i = 1; i <= N; i++)
    {
        if(cache[i]==ans){
            begin=i;
            printf("%d ", S[i-1]);
            ans--;
            continue;
        }
        
        if(begin && cache[i]==ans){
            printf("%d ", S[i-1]);
            ans--;

            if(ans==1) break;
        }
    }
}