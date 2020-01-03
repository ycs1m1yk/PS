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
const int MAX = 31;
int cache[MAX];

int tailing(int N)
{
    int &ret = cache[N];
    if (N % 2 == 1)
        return 0;
    if (N == 0)
        return 0;
    if (N == 2)
        return 3;
    if (ret != -1)
        return ret;

    ret = 3 * tailing(N - 2);
    int i = 2;
    while (N - 2 * i >= 0)
    {
        ret += 2 * tailing(N - 2 * i);
        i++;
    }
    ret += 2;
    return ret;
}

int main()
{
    int N;
    memset(cache, -1, sizeof(cache));
    cin >> N;
    cout << tailing(N);
}