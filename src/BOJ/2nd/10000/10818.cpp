#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{

    int n, minNum = 1000000, maxNum = -1000000;
    scanf("%d", &n);

    int input;
    while (--n > 0)
    {
        scanf("%d ", &input);
        minNum = min(minNum, input);
        maxNum = max(maxNum, input);
    }
    scanf("%d", &input);
    minNum = min(minNum, input);
    maxNum = max(maxNum, input);

    printf("%d %d", minNum, maxNum);

    return 0;
}