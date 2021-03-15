#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 201;
const int MOD = 1000000000;

/*

    점화식, 점화식, 점화식!!

    - X c[4][0]
    - 4 c[4][1]
    - 04 40 13 22 31
      => c[4][2] = c[4][1] + c[3][1] + c[2][1] + c[1][1] + c[0][1]
    - 004 040 400 013 022 031 103 202 301 130 220 310 112 121 211
      => c[4][3] = c[4][2] + c[3][2] + c[2][2] + c[1][2] + c[0][2]

*/

int N, K, cache[MAX][MAX];

int solve(int nn, int kk){
    if(kk==1)
        return 1;
    int &ret = cache[nn][kk];
    if(ret!=-1)
        return ret;

    ret=0;
    for(int n=nn; n>=0; n--){
        ret = (ret + solve(n, kk-1)) % MOD;
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    cout<< solve(N, K);
}