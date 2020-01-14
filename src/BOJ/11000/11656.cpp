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
    string S;
    vector<string> dict;
    getline(cin, S);
    for (int i = 0; i < S.size(); i++)
    {
        dict.push_back(S.substr(i, S.size() - i));
    }
    sort(dict.begin(), dict.end());
    for (auto s : dict)
    {
        cout << s << "\n";
    }
}