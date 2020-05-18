#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int s1 = 0, s2 = 0, s3 = 0;
    int rectangle[5][5] = {0};
    int rowTotal[5] = {0};
    int colTotal[5] = {0};

    cin >> N >> M;

    int total = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> rectangle[i][j];
            rowTotal[i] += rectangle[i][j];
            colTotal[j] += rectangle[i][j];
        }
        total += rowTotal[i];
    }

    int result = 0;
    if (N == 1)
    {
        for (int col = 0; col < M - 2; col++)
        {
            for (int i = col + 1; i < M; i++)
            {
                //
            }
        }
    }
    else if (M == 1)
    {
        for (int row = 0; row < N - 2; row++)
        {
            for (int i = row + 1; i < N; i++)
            {
                //
            }
        }
    }
    else
    {
        for (int row = 0; row < N; row++)
        {
            //
        }
        for (int col = 0; col < M; col++)
        {
            //
        }
    }
}