#include <iostream>

using namespace std;
int N, M;
long long total = 0;
long long s1, s2, s3;
int rectangle[100][100] = {0};
int rowTotal[100] = {0};
int colTotal[100] = {0};

long long getSubTotal(int r1, int r2, int c1, int c2)
{
    long long ret = 0;
    for (int row = r1; row <= r2; row++)
    {
        for (int col = c1; col <= c2; col++)
        {
            ret += rectangle[row][col];
        }
    }

    return ret;
}

long long getRowTotal(int r1, int r2)
{
    long long ret = 0;
    for (int row = r1; row <= r2; row++)
        ret += rowTotal[row];

    return ret;
}

long long getColTotal(int c1, int c2)
{
    long long ret = 0;
    for (int col = c1; col <= c2; col++)
        ret += colTotal[col];

    return ret;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &rectangle[i][j]);
            rowTotal[i] += rectangle[i][j];
            colTotal[j] += rectangle[i][j];
        }
        total += rowTotal[i];
    }

    long long result = 0;

    if (N >= 2 && M >= 2)
    {
        s1 = 0;
        for (int row = 0; row < N - 1; row++)
        {
            s1 += rowTotal[row];
            for (int col = 0; col < M; col++)
            {
                s2 = getSubTotal(row + 1, N - 1, 0, col);
                s3 = total - s1 - s2;
                result = max(result, s1 * s2 * s3);
            }
        }

        s1 = 0;
        for (int row = N - 1; row >= 1; row--)
        {
            s1 += rowTotal[row];
            for (int col = 0; col < M; col++)
            {
                s2 = getSubTotal(0, row - 1, 0, col);
                s3 = total - s1 - s2;
                result = max(result, s1 * s2 * s3);
            }
        }

        s1 = 0;
        for (int col = 0; col < M - 1; col++)
        {
            s1 += colTotal[col];
            for (int row = 0; row < N; row++)
            {
                s2 = getSubTotal(0, row, col + 1, M - 1);
                s3 = total - s1 - s2;
                result = max(result, s1 * s2 * s3);
            }
        }

        s1 = 0;
        for (int col = M - 1; col >= 1; col--)
        {
            s1 += colTotal[col];
            for (int row = 0; row < N; row++)
            {
                s2 = getSubTotal(0, row, 0, col - 1);
                s3 = total - s1 - s2;
                result = max(result, s1 * s2 * s3);
            }
        }
    }

    s1 = 0;
    if (N >= 3)
    {
        for (int row = 0; row < N - 2; row++)
        {
            s1 += rowTotal[row];
            for (int r = row + 1; r < N; r++)
            {
                s2 = getRowTotal(row + 1, r);
                s3 = total - s1 - s2;
                result = max(result, s1 * s2 * s3);
            }
        }
    }

    s1 = 0;
    if (M >= 3)
    {
        for (int col = 0; col < M - 2; col++)
        {
            s1 += colTotal[col];
            for (int c = col + 1; c < M; c++)
            {
                s2 = getColTotal(col + 1, c);
                s3 = total - s1 - s2;
                result = max(result, s1 * s2 * s3);
            }
        }
    }

    cout << result;
}