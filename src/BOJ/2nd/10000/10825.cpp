#include <iostream>
#include <algorithm>
#include <tuple>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 100000;
typedef tuple<int, int, int, string> score;

int N;
score s[MAX];

int main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        // 국어와 수학 점수는 감소순, 이름은 마지막에 비교
        s[i] = score(-kor, eng, -math, name);
    }

    // sort using the default operator<
    sort(s, s + N);

    for (int i = 0; i < N; i++)
        cout << get<3>(s[i]) << "\n";
}