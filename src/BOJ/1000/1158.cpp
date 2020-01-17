#include <iostream>
#include <list>

using namespace std;

void display(list<int> li)
{
    cout << "<";
    for (auto iter = li.begin(); iter != li.end(); iter++)
    {
        if (iter == li.begin())
            cout << *iter;
        else
            cout << ", " << *iter;
    }
    cout << ">";
}

int main()
{
    int N, K, pos;
    list<int> josephusList, resultList;
    auto delPos = josephusList.begin();

    cin >> N >> K;
    pos = K - 1;
    for (int i = 1; i <= N; i++)
    {
        josephusList.push_back(i);
    }

    while (!josephusList.empty())
    {
        for (int i = 0; i < K; i++)
        {
            auto nextPos = delPos;
            nextPos++;
            if (nextPos == josephusList.end())
            { // 다음 iter가 end라면 begin으로
                delPos = josephusList.begin();
            }
            else
            {
                delPos++;
            }
        }
        resultList.push_back(*delPos);
        delPos = josephusList.erase(delPos);
        delPos--;
        //display(josephusList);
    }
    display(resultList);
}