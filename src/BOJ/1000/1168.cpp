#include <iostream>
#include <list>

using namespace std;
/*
    1158-요세푸스 문제 1
    : (1<=K<=N<=5,000), 제한시간 2초

    1168-요세푸스 문제 2
    : (1<=K<=N<=100,000), 제한시간 1초

    1158 풀이 그대로 제출해보니 시간초과
*/

/*
    < 참 고 >
    n이 십만일 때 O(n)이나 O(nlogn)에 동작하는 코드는 당연히 통과가 되겠지만,
    이 문제를 원형 리스트로 풀려고 하면 O(n^2)이 되기 때문에 통과될 수 없는 것이 당연합니다.
    조세퍼스 문제 1은 n이 5000인데 이 때 O(n^2) 알고리즘으로 68ms가 걸리셨습니다.
    n^2은 2500만입니다. 그러면 n이 10만이면 얼마나 걸릴까요? 
    n^2은 100억입니다. 대략 400배 정도 시간이 더 걸리겠죠?
    조세퍼스 문제 2는 세그먼트 트리 등을 이용해서 O(nlogn)에 풀 수 있...(생략)

    나중에 풀어보기로..
*/
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