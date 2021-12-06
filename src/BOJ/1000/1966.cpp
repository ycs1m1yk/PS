#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    int T, N, M;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        queue<pii> task;
        priority_queue<int> pq;
        int priority;
        for (int i = 0; i < N; i++)
        {
            cin >> priority;
            task.push({priority, i});
            pq.push(priority);
        }

        for (int ans = 1;; ans++)
        {
            while (task.front().first < pq.top())
            {
                task.push(task.front());
                task.pop();
            }
            if (task.front().second == M)
            {
                cout << ans << "\n";
                break;
            }
            task.pop();
            pq.pop();
        }
    }
}