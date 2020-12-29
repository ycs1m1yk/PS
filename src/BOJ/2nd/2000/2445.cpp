#include <cstdio>
#include <cmath>

int main(){
    int n;
    scanf("%d", &n);

    int j=0;
    for(int i=0; i<2*n; i++){
        for(j=0; j<-1*abs(i-n+1)+n; j++){
            printf("*");
        }
        for(int k=0; k<n-j; k++){
            printf("  ");
        }
        for(int l=0; l<j; l++){
            printf("*");
        }
        if(i<2*n) printf("\n");
    }
}