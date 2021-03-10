#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 101;

int T, N;
unsigned long long cache[MAX];

unsigned long long padovanSeq(int num)
{
    if(num==0) return 0;
    if(num<4) return 1;
    if(num<6) return 2;
    unsigned long long &ret = cache[num];
    if(ret!=-1) return ret;

    return ret = padovanSeq(num-1) + padovanSeq(num-5);
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << padovanSeq(N) << "\n";
    }
}