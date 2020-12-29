#include <cstdio>

int main(){

    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        printf("%d", N-i);
        if(i<N-1) { printf("\n");}
    }

    return 0;
}