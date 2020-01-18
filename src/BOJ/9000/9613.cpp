#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int T, n;
    vector<int> inputVec;

    cin >> T;

    while (T--)
    {
        /*
            result의 최대값?
            입력이 100 1000000 ... 1000000(100개)일떄,
            1000000 * (99+98+...+1)
            = 1000000 * (99*100)/2 = 4,950,000,000 > INT_MAX

            따라서, result를 long타입으로 선언
        */
        long result = 0;
        cin >> n;
        while (n--)
        {
            int input;
            cin >> input;
            inputVec.push_back(input);
        }
        while (inputVec.size() > 1)
        {
            int back = inputVec.back();
            inputVec.pop_back();
            for (auto element : inputVec)
            {
                result += __gcd(back, element);
            }
        }
        cout << result << "\n";
        // result, inputVec 초기화
        result = 0;
        inputVec.clear();
    }
}