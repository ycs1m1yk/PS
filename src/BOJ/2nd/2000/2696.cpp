#include <iostream>
#include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0)
typedef long long ll;

int T, M;
ll input, mid;
priority_queue<ll> pq;
priority_queue<ll, vector<ll>, greater<ll>> pq_g;

int main()
{
    fastio;
    cin >> T;
    while (T--) {
        pq = priority_queue<ll> ();
        pq_g = priority_queue<ll, vector<ll>, greater<ll> > ();

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> input;
            if (i == 0) {
                mid = input;
                cout << (M + 1) / 2 << "\n"
                     << mid << " ";
                continue;
            }
            if (input <= mid) {
                pq.push(input);
            }
            else {
                pq_g.push(input);
            }

            if (i % 2 == 0) {
                if (pq.size() > pq_g.size()) {
                    pq_g.push(mid);
                    mid = pq.top();
                    pq.pop();
                }
                else if (pq.size() < pq_g.size()) {
                    pq.push(mid);
                    mid = pq_g.top();
                    pq_g.pop();
                }
                cout << mid << " ";
                if (i % 20 == 18 && i != M-1)
                    cout << "\n";
            }
        }
        cout << "\n";
    }
}