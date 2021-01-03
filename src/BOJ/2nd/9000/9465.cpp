#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int T, n;
int cache[MAX][2]; // cache[n][0] : 윗줄을 선택했을때 최대 점수, [1]: 아랫줄
int sticker[2][MAX];

int solve(int pos, int row)
{
    int upperRowScore = sticker[0][pos];
    int lowerRowScore = sticker[1][pos];
    if (pos == 0)
    {
        return row == 0 ? upperRowScore : lowerRowScore;
    }
    if (pos == 1)
    {
        return row == 0 ? (solve(0, 1) + upperRowScore) : (solve(0, 0) + lowerRowScore);
    }

    int &ret = cache[pos][row];
    if (ret!=-1)
        return ret;

    if (row == 0)
    {
        ret = solve(pos - 1, 1);
        ret = max(solve(pos - 2, 0), ret);
        ret = max(solve(pos - 2, 1), ret);
        ret += upperRowScore;
    }
    if (row == 1)
    {
        ret = solve(pos - 1, 0);
        ret = max(solve(pos - 2, 0), ret);
        ret = max(solve(pos - 2, 1), ret);
        ret += lowerRowScore;
    }

    return ret;
}

int main()
{
    scanf("%d", &T);

    while (T--)
    {
        memset(cache, -1, sizeof(cache));

        scanf("%d", &n);
        for (int col = 0; col < n; col++)
        {
            if (col < n - 1)
                scanf("%d ", &sticker[0][col]);
            else
                scanf("%d", &sticker[0][col]);
        }
        for (int col = 0; col < n; col++)
        {
            if (col < n - 1)
                scanf("%d ", &sticker[1][col]);
            else
                scanf("%d", &sticker[1][col]);
        }

        printf("%d\n", max(solve(n-1, 0), solve(n-1, 1)));
    }
}