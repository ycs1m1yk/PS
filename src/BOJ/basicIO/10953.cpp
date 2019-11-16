#include <cstdio>
using namespace std;

int main()
{
    int T;
    int a, b;
    scanf("%d", &T);
    while ((T > 0) && (scanf("%d,%d", &a, &b) > 0))
    {
        printf("%d\n", a + b);
        T--;
    }
    return 0;
}