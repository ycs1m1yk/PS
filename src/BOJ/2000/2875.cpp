#include <iostream>

using namespace std;
int N, M, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    int maxTeam = 0;
    while (N >= 2 && M >= 1)
    {
        N -= 2;
        M -= 1;

        if (N + M < K)
            break;

        maxTeam++;
    }

    cout << maxTeam;
}