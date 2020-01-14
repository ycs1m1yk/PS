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
const int MAX = 101;
int main()
{
    int cnt[4] = {0}; // 소문자, 대문자, 숫자, 공백 개수
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (!str[i]) // 널문자만나면 break
                break;

            if (str[i] >= 'a' && str[i] <= 'z')
                cnt[0]++;
            else if (str[i] >= 'A' && str[i] <= 'Z')
                cnt[1]++;
            else if (str[i] >= '0' && str[i] <= '9')
                cnt[2]++;
            else
                cnt[3]++;
        }
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", cnt[i]);
            cnt[i] = 0; // cnt 초기화
        }
        printf("\n");
    }
}