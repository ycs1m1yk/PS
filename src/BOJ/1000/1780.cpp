#include <iostream>
#include <math.h>

using namespace std;

const int MAX = pow(3, 7);
int N;
int arr[MAX][MAX], count[3];

void solve(int n, int r, int c)
{
    if (n == 1) // base case
        count[arr[r][c] + 1]++;
    else
    {
        bool flag = true;
        int beginNum = arr[r][c];
        for (int i = r; i < r + n; i++)
        {
            for (int j = c; j < c + n; j++)
            {
                if (arr[i][j] != beginNum)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }

        if (flag)
            count[beginNum + 1]++;
        else
        {
            solve(n / 3, r, c);
            solve(n / 3, r, c + n / 3);
            solve(n / 3, r, c + 2 * (n / 3));
            solve(n / 3, r + n / 3, c);
            solve(n / 3, r + n / 3, c + n / 3);
            solve(n / 3, r + n / 3, c + 2 * (n / 3));
            solve(n / 3, r + 2 * (n / 3), c);
            solve(n / 3, r + 2 * (n / 3), c + n / 3);
            solve(n / 3, r + 2 * (n / 3), c + 2 * (n / 3));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    solve(N, 0, 0);

    cout << count[0] << "\n"
         << count[1] << "\n"
         << count[2] << "\n";
}
