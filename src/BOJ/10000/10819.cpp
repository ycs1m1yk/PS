#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int N, A[8];

/*
    <algorithm> next_permutation 사용하기
    https://en.cppreference.com/w/cpp/algorithm/next_permutation

    혹은 순열함수 직접구현
*/

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);

    int result = 0;
    do
    {
        int sum = 0;
        for (int i = 1; i < N; i++)
            sum += abs(A[i] - A[i - 1]);
        result = max(result, sum);
    } while (next_permutation(A, A + N));

    cout << result;
}