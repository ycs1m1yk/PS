#include <iostream>
#include <string>

using namespace std;
string N;
int M;
int usableButtons[10];

bool isValid(int channel)
{
    bool ret = true;
    string ch = to_string(channel);

    for (auto e : ch)
    {
        if (usableButtons[e - '0'] == -1)
        {
            ret = false;
            break;
        }
    }

    return ret;
}

int main()
{
    cin >> N;
    cin >> M;

    int target = stoi(N);

    for (int i = 0; i < 10; i++)
        usableButtons[i] = i;

    if (M > 0)
    {
        for (int i = 0; i < M; i++)
        {
            int input;
            cin >> input;
            usableButtons[input] = -1;
        }
    }

    if (N == "100") // when target is current channel
        cout << 0;
    else if (M == 10) // When 0 to 9 buttons do not work.
        cout << ((target > 100) ? target - 100 : 100 - target);
    else
    {
        int lo = 999999, hi = 999999;
        for (int i = target; i >= 0; i--)
        {
            if (isValid(i))
            {
                lo = i;
                break;
            }
        }
        for (int i = target + 1; i <= 999999; i++)
        {
            if (isValid(i))
            {
                hi = i;
                break;
            }
        }

        int result = min(to_string(lo).size() + target - lo, to_string(hi).size() + hi - target);
        int tmp = (target > 100) ? target - 100 : 100 - target; // case: shift channel with +,- button only.
        result = min(result, tmp);
        cout << result;
    }
}