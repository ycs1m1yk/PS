#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;
/*



    시간초과...



*/
int main()
{
    string command = "LDBP";
    string input;
    int M, cursorPos, cursorLastPos;

    getline(cin, input);
    cursorLastPos = input.size() - 1;
    cursorPos = cursorLastPos;
    cin >> M;
    while (M--)
    {
        char cmd;
        cin >> cmd;
        if (cmd == command[0])
        {
            if (cursorPos > -1)
                cursorPos--;
        }
        else if (cmd == command[1])
        {
            if (cursorPos != cursorLastPos)
                cursorPos++;
        }
        else if (cmd == command[2])
        {
            if (cursorPos > -1)
            {
                input.erase(cursorPos, 1);
                cursorPos--;
                cursorLastPos--;
            }
        }
        else if (cmd == command[3])
        {
            string tmp;
            cin >> tmp;
            cursorPos++;
            cursorLastPos++;
            input.insert(cursorPos, tmp);
        }
    }
    cout << input;
}