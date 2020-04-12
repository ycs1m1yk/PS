#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_fnc(int n)
{
    cout << n << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, input;
    vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), print_fnc);
}