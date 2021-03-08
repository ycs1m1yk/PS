#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 100000;
const int MIN = -1000*MAX;

int N, S[MAX];

int main(){
    fastio;
    cin>>N;

    for(int i=0; i<N; i++) {
        cin>>S[i];
    }

    int ans = S[0];
    int sum = S[0];
    for(int i=1; i<N; i++){
        sum+=S[i];
        if(sum<S[i]){
            sum=S[i];
        }
        ans = max(ans, sum);
    }

    cout<<ans;
}