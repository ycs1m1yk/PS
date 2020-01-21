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
/*

-10  10\10 10\11 10\00 10\01 
-6   11\10 11\11 11\00 11\01
-2   00\10 00\11 00\00 00\01
2    01\10 01\11 01\00 01\01

6    01\10\10 01\10\11 01\10\00 01\10\01
10   01\11\10 01\11\11 01\11\00 01\11\01
14   01\00\10 01\00\11 01\00\00 01\00\01
18   01\01\10 01\01\11 01\01\00 01\01\01

22   01\10\10\10 01\10\10\11 01\10\10\00 01\10\10\01
.
.
.

*/

int main()
{
    long N;
    cin >> N;
    vector<pair<long long, long long>> termRange; // -2진수가 leadingTerm자리수일떄 range
    termRange.push_back(make_pair(0, 0));         // 0자리수일때(편의상)
    termRange.push_back(make_pair(0, 1));         // 1자리수일때 [0..1]
    termRange.push_back(make_pair(-2, -1));       // 2자리수일때 [-2..1]
    long long minFirst = -2, maxSecond = 1;
    for (int i = 3; i <= 33; i++) // 33자리수일때까지 set range(2^31=21억얼마)
    {
        long long first, second;
        minFirst = min(minFirst, termRange[i - 1].first);
        maxSecond = max(maxSecond, termRange[i - 1].second);
        first = minFirst + pow(-2, i - 1);
        second = maxSecond + pow(-2, i - 1);
        termRange.push_back(make_pair(first, second));
    }
    vector<int> result;
    for (int i = 33; i >= 1; i--)
    {
        if (N >= termRange[i].first && N <= termRange[i].second)
        {
            if (N == 0)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(1);
                N -= pow(-2, i - 1);
            }
        }
        else
        {
            if (!result.empty())
            {
                result.push_back(0);
            }
        }
    }
    for (auto e : result)
    {
        cout << e;
    }
}