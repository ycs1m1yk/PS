#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 100000;

/*
    다음엔 tuple을 사용하거라..
*/

int N;
vector<pair<pair<int, int>, string>> users;

int main()
{
    fastio;
    cin >> N;
    int age;
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> age >> name;
        pair<pair<int, int>, string> user = make_pair(make_pair(age, i), name);
        users.push_back(user);
    }

    sort(users.begin(), users.end(), [](const auto &left, const auto &right) {
        if (left.first.first == right.first.first)
            return left.first.second < right.first.second;
        else
            return left.first.first < right.first.first;
    });

    for (int i = 0; i < N; i++)
    {
        cout << users[i].first.first << " " << users[i].second << "\n";
    }
}