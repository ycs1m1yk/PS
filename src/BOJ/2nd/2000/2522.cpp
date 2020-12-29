#include <cstdio>
#include <cmath>

int main(){
    int n;
    scanf("%d", &n);

    int j=0;
    for(int i=0; i<2*n; i++){
        for(j=0; j<abs(i-n+1); j++){
            printf(" ");
        }
        for(int k=0; k<n-j; k++){
            printf("*");
        }
        if(i<2*n) printf("\n");
    }
}