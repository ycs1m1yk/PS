#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            printf(" ");
        }
        for(int j=n-i; j>0; j--){
            printf("*");
        }
        if(i<n) printf("\n");
    }
}