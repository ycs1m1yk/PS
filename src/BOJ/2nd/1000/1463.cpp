#include <cstdio>
#include <cstring>
#include <algorithm>

/*
    bottom-up 풀이가 나을듯
*/
using namespace std;
const int MAX=1000001;
int cache[MAX];

int dp(int x){
    if(x==1) return 0;

    int& ret = cache[x];
    if(ret!=-1) return ret;

    int result=dp(x-1)+1;
    if(x%3==0) result=min(result, dp(x/3)+1);
    if(x%2==0) result=min(result, dp(x/2)+1);    

    return ret=result;    
}

int main()
{
    int n;
    memset(cache, -1, sizeof(cache));    
    
    scanf("%d", &n);
    printf("%d", dp(n));
}