#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 500000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int card[MAX];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> card[i];
    sort(card, card + N);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int *lo, *hi, input;
        cin >> input;
        lo = lower_bound(card, card + N, input);
        hi = upper_bound(card, card + N, input);

        cout << hi - lo << " ";
    }
}