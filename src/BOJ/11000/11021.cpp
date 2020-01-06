#include <cstdio>
using namespace std;

int main()
{
    int T, n = 1;
    int a, b;
    scanf("%d", &T);
    while ((T > 0) && (scanf("%d %d", &a, &b) > 0))
    {
        printf("Case #%d: %d\n", n, a + b);
        T--;
        n++;
    }
    return 0;
}