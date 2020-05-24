#include <iostream>
#include <cstring>

/*
    bfs, dfs부터 복습하고 와야겠다..
*/
using namespace std;
const int MAX = 501;
int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int map[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(map, -1, sizeof(map));
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> map[i][j];
        }
    }
}