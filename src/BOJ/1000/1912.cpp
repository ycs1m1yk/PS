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
const int MAX = 100001;

int main()
{
    int N;
    int sequence[MAX];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &sequence[i]);
    }

    int max1 = sequence[0];
    int result = max1;
    if (N > 1)
    {
        for (int i = 1; i < N; i++)
        {
            // 이전값까지 최대연속합+현재값 vs 현재값
            max1 = max(max1 + sequence[i], sequence[i]);
            result = max(result, max1);
        }
    }

    printf("%d", result);
    return 0;
}
