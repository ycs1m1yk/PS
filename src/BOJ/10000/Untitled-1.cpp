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
    double A, B, C, D;
    int bLen, dLen;   // B와 D의 자릿수
    long long result; // LONG_LONG_MAX == 9223372036854775807

    cin >> A >> B >> C >> D;
    for (int i = 6; i >= 0; i--)
    {
        if ((B / pow(10, i)) > 0)
        {
            bLen = i + 1;
            break;
        }
    }
    for (int i = 6; i >= 0; i--)
    {
        if ((D / pow(10, i)) > 0)
        {
            dLen = i + 1;
            break;
        }
    }
    result = A * pow(10, bLen) + B + C * pow(10, dLen) + D;
    cout << result;
}