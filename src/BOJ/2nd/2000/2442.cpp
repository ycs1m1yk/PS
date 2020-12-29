#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=n-1-i; j>0; j--){
            printf(" ");
        }
        for(int j=0; j<2*(i+1)-1; j++){
            printf("*");
        }
        if(i<n) printf("\n");
    }
}