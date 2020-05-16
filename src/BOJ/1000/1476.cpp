#include <iostream>

using namespace std;
/*
    1년이 준규가 사는 나라에서 1 1 1일때, 
    준규가 사는 나라에서 E S M이 
    우리가 알고 있는 연도로 몇 년인지 구하는 프로그램을 작성하시오
*/

const int YEAR_MAX = 7980; // 15*28*19
int E, S, M;               // (1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)

int main()
{
    cin >> E >> S >> M;

    for (int i = 1; i <= YEAR_MAX; i++)
    {
        int rE = i % 15;
        int rS = i % 28;
        int rM = i % 19;
        if (rE == 0)
        {
            rE = 15;
        }
        if (rS == 0)
        {
            rS = 28;
        }
        if (rM == 0)
        {
            rM = 19;
        }
        if (rE == E && rS == S && rM == M)
        {
            cout << i;
            break;
        }
    }
}