#include <iostream>

using namespace std;

int N;
int frame[64][64];

void divNConq(int n, int r, int c)
{
    bool flag = false;
    int pivot = frame[r][c];

    if (n == 1)
    {
        cout << pivot ? '1' : '0';
    }
    else
    {
        for (int i = r; i < r + n; i++)
        {
            for (int j = c; j < c + n; j++)
            {
                if (frame[i][j] != pivot)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        if (!flag)
        {
            cout << pivot;
            // cout << ')';
        }
        else
        {
            cout << '(';
            divNConq(n / 2, r, c);
            divNConq(n / 2, r, c + n / 2);
            divNConq(n / 2, r + n / 2, c);
            divNConq(n / 2, r + n / 2, c + n / 2);
            cout << ')';
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &frame[i][j]);
        }
    }

    divNConq(N, 0, 0);
}