#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int len;

    do
    {
        getline(cin, str);
    } while (str.compare("") == 0);

    len = str.size();

    for (int i = 0; i < len; i++)
    {
        cout << str[i];
        if (i % 10 == 9)
            cout << "\n";
    }

    return 0;
}
