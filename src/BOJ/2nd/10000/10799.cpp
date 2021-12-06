#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    int c, prev = '(';
    stack<int> s;

    int ans = 0;
    while ((c = getchar()) != '\n')
    {
        if (c == ')')
        {
            s.pop();
            if (prev == '(')
                ans += s.size();
            else
                ans++;
        }
        else
            s.push(c);
        prev = c;
    }
    printf("%d", ans);
}