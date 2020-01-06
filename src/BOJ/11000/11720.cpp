#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int T, iNum, sum = 0;

    while ((T < 1) || (T > 100))
    {
        cin >> T;
    }
    for (int i = 0; i < T; i++)
    {
        scanf("%1d", &iNum);
        sum += iNum;
    }
    cout << sum;

    return 0;
}