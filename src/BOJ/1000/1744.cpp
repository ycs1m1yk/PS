#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, input;
vector<int> n, p; // negtive, positive

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        if (input > 0)
            p.push_back(input);
        else
            n.push_back(input); // 0을 negative에 포함: 남는 음수를 0과 곱하기 위해서
    }

    sort(p.begin(), p.end());
    sort(n.begin(), n.end());

    long long result = 0;
    if (!p.empty())
    {
        for (int i = p.size() - 1; i > 0; i -= 2)
        {
            if (p[i] * p[i - 1] > p[i] + p[i - 1]) // ex) 1*1=1 < 1+1=2
                result += p[i] * p[i - 1];
            else
                result += p[i] + p[i - 1];
        }
        if (p.size() % 2 == 1)
            result += p.front();
    }

    if (!n.empty())
    {
        for (int i = 0; i < n.size() - 1; i += 2)
        {
            result += n[i] * n[i + 1];
        }
        if (n.size() % 2 == 1)
            result += n.back();
    }

    cout << result;
}
