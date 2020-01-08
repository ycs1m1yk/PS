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
#include <tuple>

using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());

    printf("%d", v[K - 1]);
}