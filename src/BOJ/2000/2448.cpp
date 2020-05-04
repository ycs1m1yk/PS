#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 6143;

int N, pivot = (MAX - 1) / 2;
bool stars[MAX][MAX];

void divNConq(int n, int r, int c)
{
    if (n == 3)
    {
        stars[r][c] = true;
        stars[r + 1][c - 1] = true;
        stars[r + 1][c + 1] = true;
        for (int i = -2; i <= 2; i++)
        {
            stars[r + 2][c + i] = true;
        }
        return;
    }
    else
    {
        divNConq(n / 2, r, c);
        divNConq(n / 2, r + (n / 2), c - (n / 2));
        divNConq(n / 2, r + (n / 2), c + (n / 2));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    divNConq(N, 0, pivot);

    for (int i = 0; i < N; i++)
    {
        for (int j = pivot - (N - 1); j <= pivot + (N - 1); j++)
        {
            if (stars[i][j])
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
}