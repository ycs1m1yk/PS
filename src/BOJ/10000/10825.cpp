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
typedef tuple<int, int, int, string> results;
results resultsTuple[100000];

bool cmp(const results T1, const results T2)
{
    if (get<0>(T1) == get<0>(T2)) //국어
    {
        if (get<1>(T1) == get<1>(T2)) //영어
        {
            if (get<2>(T1) == get<2>(T2)) //수학
            {
                return get<3>(T1) < get<3>(T2); //이름
            }
            else
            {
                return get<2>(T1) > get<2>(T2);
            }
        }
        else
        {
            return get<1>(T1) < get<1>(T2);
        }
    }
    else
    {
        return get<0>(T1) > get<0>(T2);
    }
}

int main()
{
    int N, kr, en, math;
    string name;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> name >> kr >> en >> math;
        resultsTuple[i] = results(kr, en, math, name);
    }
    sort(resultsTuple, resultsTuple + N, cmp);
    for (int i = 0; i < N; i++)
    {
        cout << get<3>(resultsTuple[i]) << "\n";
    }
}