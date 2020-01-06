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
const int MAX = 1001;

int dp[MAX];

int f(int input)
{
    if (input == 1)
    {
        return 1;
    }
    if (input == 2)
    {
        return 3;
    }

    if (dp[input] != -1)
    {
        return dp[input];
    }

    return dp[input] = (f(input - 1) + 2 * f(input - 2)) % 10007;
}

int main()
{
    int input = 0;
    scanf("%d", &input);
    fill(dp, dp + MAX, -1);
    printf("%d", f(input));
}