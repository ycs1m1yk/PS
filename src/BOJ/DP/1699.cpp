#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

/*
    DP활용법은 잘 모르겠다, 반례가 뭐 있지..?
*/
using namespace std;
const int MAX = 100000;

int min1 = MAX, cache[MAX];

int solve(int N)
{
    int &ret = cache[N];
    int rootN = (int)floor(sqrt(N));
    if (N == rootN * rootN)
    {
        return ret = 1;
    }
    if (ret != -1)
    {
        return ret;
    }

    for (int i = rootN; i > 0; i--)
    {
        int tmp = N;
        int cnt = 0;
        for (int j = i; j > 0; j--)
        {
            while (tmp - j * j >= 0)
            {
                tmp -= j * j;
                cnt++;
            }
        }
        min1 = min(min1, cnt);
    }
    return ret = min1;
}

int main()
{
    int N;
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    printf("%d", solve(N));
}
