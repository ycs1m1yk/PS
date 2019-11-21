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

/*
아직 미해결ㅜㅜ
*/

using namespace std;

const int MAX = 100001;
int sticker[2][MAX];
vector<int> sum;

int dp(int case, int n)
{
    int % ret = sticker[case][n];

    if (case == 0)
    {
        ret = max(ret, );
    }
}

int main()
{
    int T, n;
    int value;

    memset(sticker, -1, sizeof(sticker));
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                scanf("%d", &value);
            }
            else
            {
                scanf("%d ", &value);
            }
            sticker[0][i] = value;
        }
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                scanf("%d", &value);
            }
            else
            {
                scanf("%d ", &value);
            }
            sticker[1][i] = value;
        }

        printf("%d\n", dp(n));
        memset(sticker, -1, sizeof(sticker));
    }
}