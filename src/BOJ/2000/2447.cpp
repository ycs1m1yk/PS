#include <iostream>
#include <cmath>

using namespace std;
const int MAX = pow(3, 8);

int N;
bool stars[MAX][MAX];

void divNConq(int n, int r, int c)
{
    if (n == 1)
    { // base case
        stars[r][c] = true;
        return;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1)
                    continue;

                divNConq(n / 3, r + i * (n / 3), c + j * (n / 3));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    divNConq(N, 0, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (stars[i][j])
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
}