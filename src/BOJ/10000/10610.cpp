#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string N;
    bool isMutiplesOfThree = false; // 숫자들의 합이 3의 배수이면 true
    int sum;
    int nArr[10]; // 0~9 숫자개수

    memset(nArr, 0, sizeof(nArr));

    cin >> N;
    for (auto e : N) // nArr 초기화
    {
        int i = e - '0';
        sum += i;
        nArr[i]++;
    }

    if (sum % 3 == 0)
        isMutiplesOfThree = true;

    if (nArr[0] != 0 && isMutiplesOfThree)
    {
        for (int i = 9; i >= 0; i--)
            for (int j = nArr[i]; j > 0; j--)
                cout << i;
    }
    else
        cout << -1;
}