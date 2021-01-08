#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX = 1000;

int N, seq[MAX], cache[MAX];

int solve(int pos){
    if(pos==0){
        return 1;
    }
    int& ret = cache[pos];
    if(ret!=-1) return ret;

    ret=1;
    for(int i=pos-1; i>=0; i--){
        if(seq[i]>seq[pos]){
            ret=max(ret, solve(i)+1);
        }
    }

    return ret;
}

int main(){
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));

    for(int i=0; i<N; i++){
        scanf("%d", &seq[i]);        
    }

    int result=0;
    for(int i=0; i<N; i++){
        result=max(result, solve(i));        
    }

    printf("%d", result);
}