#include <iostream>
#include <cstring>
#include <algorithm>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 1000;

int N, S[MAX], cache1[MAX], cache2[MAX];

int lis(int start)
{
    if(start==N) return 0;
    int &ret = cache1[start];
    if(ret!=-1) return ret;

    ret=0;
    for(int prev=start-1; prev>=0; prev--){
        if(S[prev]<S[start])
            ret = max(ret, lis(prev));        
    }

    return ++ret;
}

int lds(int start)
{
    if(start==N) return 0;
    int &ret = cache2[start];
    if(ret!=-1) return ret;

    ret=0;
    for(int next=start+1; next<N; next++){
        if(S[start]>S[next])
            ret = max(ret, lds(next));        
    }

    return ++ret;
}

int main()
{
    fastio;
    cin >> N;
    memset(cache1, -1, sizeof(cache1));
    memset(cache2, -1, sizeof(cache2));

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, lis(i) + lds(i) - 1);
    }

    cout << ans;
}