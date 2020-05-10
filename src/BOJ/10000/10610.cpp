#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string N;
    int nArr[10]; // 0~9 숫자개수
    memset(nArr, 0, sizeof(nArr));

    cin >> N;
    for (auto e : N) // nArr 초기화
    {
        int i = e - '0';
        nArr[i]++;
    }

    if (nArr[0] == 0)
    {
        cout << -1;
    }
    else
    {
        // 30의 배수가 되는 가장 큰 수 찾기
    }
}