#include <iostream>
#include <cstdio>
#include <cmath>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>
#include "windows.h" // Sleep()

using namespace std;

int main()
{
    int K, N;
    long long LAN[10000], lo = 1, hi = 0;
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++)
    {
        scanf("%lld", LAN + i);
        hi = max(hi, LAN[i] + 1);
    }

    while (lo + 1 < hi)
    {
        long long mid = (lo + hi) / 2, cnt = 0;
        for (int i = 0; i < K; i++)
        {
            cnt += LAN[i] / mid;
        }
        if (cnt >= N)
            lo = mid;
        else
            hi = mid;

        // printf("lo: %lld, hi: %lld\n", lo, hi);
        // Sleep(500);
    }

    printf("%lld\n", lo);
}