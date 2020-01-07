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

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

int main()
{
    int N, x, y;
    vector<pair<int, int>> xyVec;

    scanf("%d", &N);
    while (N--)
    {
        scanf("%d %d", &x, &y);
        xyVec.push_back(make_pair(x, y));
    }
    sort(xyVec.begin(), xyVec.end(), cmp);
    for (auto &p : xyVec)
    {
        cout << p.first << " " << p.second << "\n";
    }
}