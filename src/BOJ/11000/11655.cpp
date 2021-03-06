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
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string S;
    getline(cin, S);
    for (auto &ch : S)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = lowercase[(ch - 'a' + 13) % 26];
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = uppercase[(ch - 'A' + 13) % 26];
        }
        else
            continue;
    }
    cout << S;
}