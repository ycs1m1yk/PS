#include <iostream>
#include <algorithm>
#include <tuple>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 100000;
typedef tuple<string, int, int, int> score;

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
        // 영어 점수는 증가순
        s[i] = score(name, kor, -1 * eng, math);
    }

    sort(s, s + N, [](const auto &left, const auto &right) {
        // 이름을 int형으로 비교한다.
        int rc = get<0>(left).compare(get<0>(right));
        int zero = 0;
        // 이름이 증가순이므로 left에 zero, right에 rc값을 비교
        return tie(get<1>(left), get<2>(left), get<3>(left), zero) > tie(get<1>(right), get<2>(right), get<3>(right), rc);
    });

    for (int i = 0; i < N; i++)
        cout << get<0>(s[i]) << "\n";
}