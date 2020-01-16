#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

using namespace std;

int main()
{
    int M;
    string input;
    list<char> sentence;

    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        sentence.push_back(input[i]);
    }
    list<char>::iterator cursorPos = sentence.end();

    cin >> M;
    while (M--)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'L')
        {
            if (cursorPos != sentence.begin())
            {
                cursorPos--;
            }
        }
        else if (cmd == 'D')
        {
            if (cursorPos != sentence.end())
            { // 커서가 문장의 맨 뒤
                cursorPos++;
            }
        }
        else if (cmd == 'B')
        {
            if (cursorPos != sentence.begin())
            {
                cursorPos--;
                //  erase returns Iterator following the last removed element.
                cursorPos = sentence.erase(cursorPos);
            }
        }
        else if (cmd == 'P')
        {
            char tmp;
            cin >> tmp;
            //  insert returns Iterator pointing to the inserted value
            sentence.insert(cursorPos, tmp);
        }
    }
    for (auto iter = sentence.begin(); iter != sentence.end(); iter++)
    {
        cout << *iter;
    }
}