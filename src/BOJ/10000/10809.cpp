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
    int cnt[26];
    char S[MAX];
    memset(cnt, -1, sizeof(cnt));
    scanf("%s", S);
    for (int i = 0; i < sizeof(S); i++)
    {
        if (!S[i]) // null문자 만나면 break
            break;
        if (cnt[S[i] - 'a'] != -1)
        {
            continue;
        }
        else
        {
            cnt[S[i] - 'a'] = i;
        }
    }
    for (auto pos : cnt)
    {
        printf("%d ", pos);
    }
}