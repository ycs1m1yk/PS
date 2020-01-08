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
    int N;
    vector<long long> v;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        long long input;
        scanf("%lld", &input);
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    int cnt = 1, maxCnt = 0;
    long long maxCntNum = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
        {
            cnt++;
        }
        else
        {
            if (cnt > maxCnt)
            {
                maxCnt = cnt;
                maxCntNum = v[i - 1];
            }
            cnt = 1;
        }
    }
    // 맨 뒤에 정렬된 숫자가 maxCnt인 case
    if (cnt > maxCnt)
    {
        maxCntNum = v[v.size() - 1];
    }

    printf("%lld", maxCntNum);
}