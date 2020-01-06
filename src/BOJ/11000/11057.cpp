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

const int MOD = 10007;
int increasingNum[1001][10] = {
    0,
};

int increase(int input, int val)
{
    if (input == 1)
    {
        return 1;
    }
    int &ret = increasingNum[input][val];
    if (ret != 0)
    {
        return ret;
    }

    for (int i = 0; i < val + 1; i++)
    {
        ret += increase(input - 1, i);
        ret %= MOD;
    }

    return ret;
}

int main()
{
    int N, result = 0;
    scanf("%d", &N);
    for (int i = 0; i < 10; i++)
    {
        result += increase(N, i);
        result %= MOD;
    }
    printf("%d", result);
}