#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX = 1000;

int N, sequence[MAX], cache[MAX];
/*
    TEST CASE
        
        11
        1 4 100 2 50 60 3 5 6 7 8

        10
        1 2 3 100 101 102 10 11 12 13
*/

int solve(int pos){
    if(pos==0){
        return sequence[0];
    }
    
    int& ret=cache[pos];
    if(ret!=-1) return ret;

    ret = sequence[pos];
    for(int i=0; i<pos; i++){
        if(sequence[i]<sequence[pos]){
            ret=max(ret, solve(i)+sequence[pos]);
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &sequence[i]);
    }

    int result = sequence[0];
    for(int i=0; i<N; i++){
        result=max(result, solve(i));
    }

    printf("%d", result);
}