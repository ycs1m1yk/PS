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
    for (auto coef = input.begin(); coef != input.end(); coef++)
    {
        binary.push_back(*coef - '0');
    }
    int size = binary.size() / 3;
    while (!binary.empty())
    {
        int octCoef = 0;
        for (int i = 0; i < 3; i++)
        {
            if (!binary.empty())
            {
                octCoef += binary.back() * pow(2, i);
                binary.pop_back();
            }
            else
            {
                break;
            }
        }
        octal.push_back(octCoef);
    }
    for (auto e = octal.rbegin(); e != octal.rend(); e++)
    {
        cout << *e;
    }
}