#include <iostream>

using namespace std;
int N, M;

int main()
{
    int result = 0;

    cin >> N >> M;

    if (N == 1 || M == 1)
        result = 1;
    else if (N == 2)
    {
        if (M >= 7)
            result = 4;
        else
            result = (M + 1) / 2;
    }
    else
    {
        if (M >= 7)
            result = M - 2;
        else if (M >= 4)
            result = 4;
        else
            result = M;
    }

    cout << result;
}