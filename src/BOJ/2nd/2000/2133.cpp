#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 31;

int N, cache[MAX];
int tailing(int w)
{
    // w가 0 또는 홀수이면 경우의수는 0가지
    if (w == 0 || w % 2 == 1)
        return 0;
    // base case
    if (w == 2)
        return 3;
    int &ret = cache[w];
    if (ret != -1)
        return ret;

    ret = 3 * tailing(w - 2) + 2;
    for(int i=w-4; i>=0; i-=2){
        ret += 2*tailing(i);
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> N;
    cout << tailing(N);
}