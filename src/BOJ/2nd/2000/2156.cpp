#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 10000;
const int CASE = 6;
/*
    CASE    0   1   2   3   4   5
            001 010 011 100 101 110
*/
int wine[MAX];
int cache[MAX][CASE];

int main()
{
    int n;
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wine[i]);
    }
    cache[0][0] = wine[0];
    cache[0][1] = 0;
    cache[0][2] = wine[0];
    cache[0][3] = 0;
    cache[0][4] = wine[0];
    cache[0][5] = 0;
    for (int i = 1; i < n; i++)
    {
        cache[i][0] = cache[i - 1][3] + wine[i];
        cache[i][1] = max(cache[i - 1][0], cache[i - 1][4]);
        cache[i][2] = max(cache[i - 1][0], cache[i - 1][4]) + wine[i];
        cache[i][3] = max(cache[i - 1][1], cache[i - 1][5]);
        cache[i][4] = max(cache[i - 1][1], cache[i - 1][5]) + wine[i];
        cache[i][5] = cache[i - 1][2];
    }

    int result = 0;
    for (int i = 0; i < CASE; i++)
        result = max(result, cache[n - 1][i]);

    printf("%d", result);
}