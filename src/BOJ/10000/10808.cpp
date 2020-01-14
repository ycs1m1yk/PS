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
    int cnt[26] = {0};
    cnt[25] = 1000;
    char S[MAX];
    scanf("%s", S);
    for (auto letter : S)
    {
        if (!letter) // null문자 만나면 break
            break;
        cnt[letter - 'a']++;
    }
    for (auto pos : cnt)
    {
        if (pos >= 1000)
            printf("%d ", pos - 1000);
        else
            printf("%d ", pos);
    }
}