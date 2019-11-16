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
const int MAX = 11;

int dp[MAX];

int f(int N)
{
    if (N == 1)
    {
        return 1;
    }
    if (N == 2)
    {
        return 2;
    }
    if (N == 3)
    {
        return 4;
    }

    return dp[N] = f(N - 1) + f(N - 2) + f(N - 3);
}

int main()
{
    int T, input;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        cin >> input;
        printf("%d\n", f(input));
    }
}