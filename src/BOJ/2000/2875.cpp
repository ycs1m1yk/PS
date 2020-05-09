#include <iostream>

using namespace std;
int N = 0;

void mmss(int n)
{
    int mm = n / 60;
    int ss = n % 60;
    cout << n << " = " << mm << ':' << ss << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 1000; i++)
    {
        cin >> N;

        if (N == -1)
            break;
        else
            mmss(N);
    }

    return 0;
}