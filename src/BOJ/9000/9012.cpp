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
const int MAX_LENGTH = 51;

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int lCnt = 0, rCnt = 0;
        char parenthesisStr[MAX_LENGTH] = {
            0,
        };
        scanf("%s", parenthesisStr);

        if (parenthesisStr[0] == ')')
        { // ')'로 시작하는 case
            printf("NO\n");
            continue;
        }
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            if (parenthesisStr[i] == '(')
                lCnt++;
            else if (parenthesisStr[i] == ')')
                rCnt++;

            if (lCnt < rCnt)
            { // 항상 '('개수 >= ')'개수
                printf("NO\n");
                break;
            }
            if (i == MAX_LENGTH - 1)
            { // 마지막엔 '('개수 == ')'개수
                if (lCnt == rCnt)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
}