#include <cmath> // abs()
#include <string>
#include <vector>
using namespace std;
// mapping index: 100 + row*10 + col
int keypad[10] = {131, 100, 101, 102, 110, 111, 112, 120, 121, 122};
string answer2 = "";
int lPos = 130, rPos = 132;

void writeHandPos(bool isRight, int num)
{
    if (isRight)
    {
        answer2 += "R";
        rPos = keypad[num];
    }
    else
    {
        answer2 += "L";
        lPos = keypad[num];
    }
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    for (auto num : numbers)
    {
        if (keypad[num] % 10 == 0) // left col
            writeHandPos(0, num);
        else if (keypad[num] % 10 == 2) // right col
            writeHandPos(1, num);
        else
        {
            int lDist, rDist;
            lDist = abs(((lPos - 100) / 10) - ((keypad[num] - 100) / 10)) + abs(((lPos - 100) % 10) - ((keypad[num] - 100) % 10));
            rDist = abs(((rPos - 100) / 10) - ((keypad[num] - 100) / 10)) + abs(((rPos - 100) % 10) - ((keypad[num] - 100) % 10));

            if (lDist == rDist)
            {
                if (hand.compare("right") == 0)
                {
                    writeHandPos(1, num);
                }
                else
                {
                    writeHandPos(0, num);
                }
            }
            else
            {
                if (rDist < lDist)
                    writeHandPos(1, num);
                else
                    writeHandPos(0, num);
            }
        }
    }
    answer = answer2;
    return answer;
}