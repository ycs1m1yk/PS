#include <stdio.h>

int main()
{
    /*
        getchar(), putchar() 익숙해지자!!!
    */
    char buf[100];
    while(fgets(buf, sizeof(buf), stdin)!=NULL){
        printf("%s", buf);
    }

    return 0;
}