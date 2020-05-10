#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string N;
    bool isMutiplesOfThree = false; // 숫자들의 합이 3의 배수이면 true
    int sum = 0;
    int nArr[10]; // 0~9 숫자개수

    memset(nArr, 0, sizeof(nArr)); // nArr 초기화

    cin >> N;

    for (auto e : N) // nArr 입력
    {
        sum += e - '0';
        nArr[e - '0']++;
    }

    if (sum % 3 == 0)
        isMutiplesOfThree = true;

    if (nArr[0] != 0 && isMutiplesOfThree)
    {
        for (int i = 9; i >= 0; i--)
            for (int j = nArr[i]; j > 0; j--)
            {
                char ch = i + '0';
                cout << ch;
            }
    }
    else
        cout << "-1";
}