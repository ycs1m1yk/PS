#include <iostream>
#include <stack>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    stack<int> s;
    string input;

    cin >> input;
    for (auto ch : input)
        s.push(ch);

    int stickCnt = 0, ans = 0;
    char prevParentheses;
    while (!s.empty())
    {
        if (s.top() == ')')
        {
            stickCnt++;
        }
        else
        {
            stickCnt--;
            // lazor case
            if (prevParentheses == ')')
                ans += stickCnt;
            else{
                ans++;
            }
        }
        prevParentheses = s.top();
        s.pop();
    }

    cout<<ans;
}