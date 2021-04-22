#include <iostream>
#include <stack>
#include <string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
/*
    스택 활용
*/
int T;
stack<int> s;
string input;

int main()
{
    fastio;
    cin >> T;
    while (T--)
    {
        int cnt = 0;
        cin >> input;

        // "NO" cases
        if (input.front() == ')' || input.back() == '(' || input.length() % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            for (auto ch : input)
                s.push(ch);

            // solve
            while (!s.empty())
            {
                if (cnt < 0)
                    break;

                if (s.top() == ')')
                    cnt++;
                else
                    cnt--;
                s.pop();
            }

            // print result
            if (cnt == 0)
                cout << "YES\n";
            else
                cout << "NO\n";

            while (!s.empty())
                s.pop();
        }
    }
}