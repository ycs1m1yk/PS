#include <cstdio>

int main()
{
    char ch;
    int cnt = 0;
    
    while ((ch = getchar())!=EOF){
        putchar(ch);
        cnt++;
        if (cnt == 10)
        {
            cnt = 0;
            putchar('\n');
        }
    }

    return 0;
}