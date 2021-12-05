#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Alpha
{
    int cnt;
    int idx;
} a[26];

int main()
{
    int T;
    string str;

    cin >> T;
    getline(cin, str);
    while (T--)
    {
        for (int i = 0; i < 26; i++)
        {
            a[i].cnt = 0;
            a[i].idx = i;
        }
        
        getline(cin, str);
        for (auto ch : str){
            if(ch!=' ')
                a[ch - 'a'].cnt++;
        }
        sort(a, a + 26, [](const Alpha &a, const Alpha &b)
             { return a.cnt > b.cnt; });
        if (a[0].cnt == a[1].cnt)
        {
            cout << "?\n";
        }
        else
        {
            char answer = 'a' + a[0].idx;
            cout << answer << "\n";
        }
    }

    return 0;
}
