#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 1001;

int N, price[MAX], cache[MAX];

int pay_max_price(int c){
    if(c==1) return price[1];
    int &ret = cache[c];
    if(ret!=-1) return ret;

    ret = price[c];
    for(int i=1; i<=c/2; i++){
        ret=max(ret, pay_max_price(i)+pay_max_price(c-i));
    }
    return ret;
}
int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> price[i];
    
    cout << pay_max_price(N);
}