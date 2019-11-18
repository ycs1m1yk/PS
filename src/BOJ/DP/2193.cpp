#include <iostream>
#include <stdio.h>
#include <math.h>
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

long long pinaryNum[91][2] = {
    0,
};

long long pinary(int input, int val)
{
    if (input == 1)
    {
        if (val == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    long long &ret = pinaryNum[input][val];
    if (ret != 0)
    {
        return ret;
    }

    if (val == 0)
    {
        ret += pinary(input - 1, 0);
        ret += pinary(input - 1, 1);
    }
    else
    {
        ret += pinary(input - 1, 0);
    }

    return ret;
}

int main()
{
    int N;
    long long result = 0;
    scanf("%d", &N);
    for (int i = 0; i < 2; i++)
    {
        result += pinary(N, i);
    }
    printf("%lld", result);
}