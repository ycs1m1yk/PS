#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, input;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int result = 0;
    for (int i = 0; i < v.size(); i++)
    {
        result += v[i] * (v.size() - i);
    }

    cout << result;
}