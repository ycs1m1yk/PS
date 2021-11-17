#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str) && str != "END")
    {
        for (auto iter = str.rbegin(); iter != str.rend(); ++iter)
        {
            cout << *iter;
        }
        cout << "\n";
    }
}