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
<<<<<<< HEAD
    시간초과...
*/

using namespace std;
const int MAX = 100000;
const int ROOT_MAX = 317; // sqrt(100000) == 316.xx...

int min1 = MAX, cache[MAX], cnt[ROOT_MAX];
=======
    DP활용법은 잘 모르겠다, 반례가 뭐 있지..?
*/
using namespace std;
const int MAX = 100000;

int min1 = MAX, cache[MAX];
>>>>>>> a6d68a3fef2262c2feb6767b03238791e974ada0

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

    for (int i = 1; i < rootN + 1; i++)
    {
        cnt[i] = N / (i * i);
    }

    for (int i = rootN; i > 0; i--)
    {
        int tmp = N;
        for (int j = cnt[i]; j >= 0; j--)
        {
            tmp -= j * i * i;
            int s = solve(tmp);
            if (ret == -1)
            {
                ret = j + s;
            }
            else
            {
                ret = min(ret, j + s);
            }
            tmp = N;
        }
    }
    return ret;
}

int main()
{
    int N;
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    printf("%d", solve(N));
}
