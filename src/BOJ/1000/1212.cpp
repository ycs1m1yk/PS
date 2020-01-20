#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;
int main()
{
    string input;
    vector<int> binary, octal;
    cin >> input;
    // 수가 0일경우
    if (input == "0")
    {
        cout << 0;
        return 0;
    }
    for (auto coef = input.begin(); coef != input.end(); coef++)
    {
        octal.push_back(*coef - '0');
    }
    for (auto e = octal.begin(); e != octal.end(); e++)
    {
        int tmp = *e;
        for (int i = 2; i >= 0; i--)
        {
            if (tmp / pow(2, i) >= 1)
            {
                binary.push_back(1);
                tmp -= pow(2, i);
            }
            else
            {
                binary.push_back(0);
            }
        }
    }

    bool isFirstOne = false;
    for (auto e = binary.begin(); e != binary.end(); e++)
    {
        if (*e == 1)
            isFirstOne = true;
        if (isFirstOne)
            cout << *e;
    }
}
