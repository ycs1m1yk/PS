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
    int N, age;
    string name;
    vector<pair<int, int>> ageOrderVec;
    vector<string> nameVec;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        cin >> age >> name;
        ageOrderVec.push_back(make_pair(age, i));
        nameVec.push_back(name);
    }
    sort(ageOrderVec.begin(), ageOrderVec.end(), cmp);
    for (int i = 0; i < ageOrderVec.size(); i++)
    {
        cout << get<0>(ageOrderVec[i]) << " " << nameVec[get<0>(ageOrderVec[i])] << "\n";
    }
}