#include <iostream>
#include <cstdio>
#include <cmath>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>
#include <iomanip>

using namespace std;
const int MAX = 102;
int M, N, H;
int dh[6] = {0, 0, 0, 0, 1, -1};
int dn[6] = {0, 0, 1, -1, 0, 0};
int dm[6] = {1, -1, 0, 0, 0, 0};
int box[MAX][MAX][MAX];
int d[MAX][MAX][MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<int, pair<int, int>>> Q; // {h, {n, m}}
    memset(d, -1, sizeof(d));
    cin >> M >> N >> H;
    // 테두리(-1) 그리기
    memset(box[0], -1, sizeof(box[0]));
    memset(box[H + 1], -1, sizeof(box[H + 1]));
    for (int h = 1; h <= H; h++)
    {
        for (int i = 0; i <= M + 1; i++)
        {
            box[h][0][i] = box[h][N + 1][i] = -1;
        }
        for (int j = 0; j <= N + 1; j++)
        {
            box[h][j][0] = box[h][j][M + 1] = -1;
        }
    }
    // 토마토 입력
    for (int h = 1; h <= H; h++)
    {
        for (int n = 1; n <= N; n++)
        {
            for (int m = 1; m <= M; m++)
            {
                cin >> box[h][n][m];
                if (box[h][n][m] == 1)
                {
                    Q.push({h, {n, m}});
                    d[h][n][m] = 0;
                }
            }
        }
    }
    // BFS 수행
    while (!Q.empty())
    {
        int hereH = Q.front().first;
        int hereN = Q.front().second.first;
        int hereM = Q.front().second.second;
        Q.pop();
        for (int i = 0; i < 6; i++)
        {
            int thereH = hereH + dh[i];
            int thereN = hereN + dn[i];
            int thereM = hereM + dm[i];
            if (box[thereH][thereN][thereM] == 0 && d[thereH][thereN][thereM] == -1)
            {
                d[thereH][thereN][thereM] = d[hereH][hereN][hereM] + 1;
                Q.push({thereH, {thereN, thereM}});
            }
        }
    }
    // // box 출력
    // cout << "box출력:\n";
    // for (int h = 0; h <= H + 1; h++)
    // {
    //     for (int n = 0; n <= N + 1; n++)
    //     {
    //         for (int m = 0; m <= M + 1; m++)
    //         {
    //             cout << box[h][n][m] << setw(3);
    //         }
    //         cout << "\n";
    //     }
    //     cout << ">>>>>>>>>>>>>>>>>\n";
    // }
    // // d 출력
    // cout << "d출력:\n";
    // for (int h = 0; h <= H + 1; h++)
    // {
    //     for (int n = 0; n <= N + 1; n++)
    //     {
    //         for (int m = 0; m <= M + 1; m++)
    //         {
    //             cout << d[h][n][m] << setw(3);
    //         }
    //         cout << "\n";
    //     }
    //     cout << ">>>>>>>>>>>>>>>>>\n";
    // }
    // 결과찾기
    int result = 0;
    for (int h = 1; h <= H; h++)
    {
        if (result == -1)
            break;
        for (int n = 1; n <= N; n++)
        {
            if (result == -1)
                break;
            for (int m = 1; m <= M; m++)
            {
                if (box[h][n][m] == 0 && d[h][n][m] == -1)
                {
                    result = -1;
                    break;
                }
                result = max(result, d[h][n][m]);
            }
        }
    }

    cout << result << "\n";
}