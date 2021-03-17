#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 1000001;

int N;
vector<int> v;

int main()
{
    fastio;
    cin >> N;
    int input;
    while (N--)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for(auto e:v)
        cout << e << "\n";
}