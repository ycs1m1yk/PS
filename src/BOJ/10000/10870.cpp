#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map<int, long long> results;

long long fib(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    map<int, long long>::iterator ii = results.find(n);
    if(ii!=results.end())
        return (*ii).second;
    else
        return results[n] = fib(n-1) + fib(n-2);
}

int main(){
    int N;
    scanf("%d", &N);
    printf("%lld", fib(N));
}