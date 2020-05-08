#include <iostream>

using namespace std;

int N, K;
int A[10];

int coinChange(int total, int *coinValArr)
{
    int ret = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        ret += K / A[i];
        K %= A[i];
        if (K == 0)
            break;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << coinChange(K, A);
}