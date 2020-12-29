#include <cstdio>

int main(){

    int N;
    scanf("%d", &N);
    for(int i=1; i<=9; i++) {
        printf("%d * %d = %d", N,i,N*i);
        if(i<9) { printf("\n");}
    }

    return 0;
}