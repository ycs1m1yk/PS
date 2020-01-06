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

using namespace std;
const int MAX = 101;

long long cache[MAX];

long long padovanSeq(int N)
{
    long long &ret = cache[N];
    if (N < 4)
        return 1;
    if (N < 6)
        return 2;
    if (ret != -1)
        return ret;

    return ret = padovanSeq(N - 1) + padovanSeq(N - 5);
}

int main()
{
    int T, N;
    memset(cache, -1, sizeof(cache));

    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &N);
        cout << padovanSeq(N) << "\n";
    }
}