#include <cstdio>

int main()
{
    char buf[100];
    while(fgets(buf, sizeof(buf), stdin)!=NULL){
        printf("%s", buf);
    }

    return 0;
}