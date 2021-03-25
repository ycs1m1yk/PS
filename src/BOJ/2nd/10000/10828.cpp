#include <iostream>
#include <cstring>
#include <stack>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N;
stack<int> st;

int main()
{
    fastio;
    cin >> N;
    string op;
    while (N--)
    {
        cin >> op;
        if (op.compare("push") == 0)
        {
            int X;
            cin >> X;
            st.push(X);
        }
        else if (op.compare("pop") == 0)
        {
            if (st.empty())
                cout << -1 << "\n";
            else
            {

                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (op.compare("size") == 0)
        {
            cout << st.size() << "\n";
        }
        else if (op.compare("empty") == 0)
        {
            cout << st.empty() << "\n";
        }
        else if (op.compare("top") == 0)
        {
            cout << (st.empty() ? -1 : st.top()) << "\n";
        }
    }
}