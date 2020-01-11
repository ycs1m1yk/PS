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
    stack<int> openingStack;
    vector<int> lazorPos;
    vector<pair<int, int>> ironBars;

    getline(cin, input);
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            openingStack.push(i);
        }
        else
        {
            // 레이져일 경우
            if (input[i - 1] == '(')
                lazorPos.push_back(i);
            // 쇠막대기의 끝점일 경우
            else
                ironBars.push_back(make_pair(openingStack.top(), i));

            openingStack.pop();
        }
    }

    int ret = 0;
    for (int i = 0; i < ironBars.size(); i++)
    {
        int lazorCnt = 0;
        for (int j = 0; j < lazorPos.size(); j++)
        {
            // 현재 쇠막대기에 레이저커팅이 몇번되는지 카운트
            if (lazorPos[j] > ironBars[i].first && lazorPos[j] < ironBars[i].second)
            {
                lazorCnt++;
            }
        }
        ret += lazorCnt + 1;
    }
    printf("%d", ret);
}
