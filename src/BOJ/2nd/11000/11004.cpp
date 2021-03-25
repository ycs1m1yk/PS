#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 5000000;
/*
    nth_element()!!
*/
int N, K, A[MAX];

int main()
{
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    nth_element(A, A + K - 1, A + N);
    cout << A[K - 1];
}