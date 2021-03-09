#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 300;

int N, stair[MAX], cache[MAX];

int solve(int pos){
    if(pos<2) return pos==0? stair[0] : stair[0]+stair[1];
    int &ret = cache[pos];
    if(ret!=-1) return ret;

    if(pos==2) return ret = max(stair[0]+stair[2], stair[1]+stair[2]);
    ret=stair[pos]+solve(pos-2); // ? o x o
    ret = max(ret, solve(pos-3)+stair[pos-1]+stair[pos]); // o x o o

    return ret;
}

int main(){
    fastio;
    memset(cache, -1, sizeof(cache));
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>stair[i];
    }
    cout<<solve(N-1);
}