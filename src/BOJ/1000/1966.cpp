#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int T, N, M;

    cin >> T;
    while (T--) {
        cin >> N >> M;
        queue<pii> task, done;
        priority_queue<int, vector<int>, less<int> > sorted;
        int priority, minPriority=10;
        for(int i = 0; i < N; i++){
            cin >> priority;
            minPriority = min(minPriority, priority);
            task.push({priority, i});           
            sorted.push(priority);           
        }

        while(!task.empty()){
            int now = sorted.top();
            if(now!=minPriority){
                while(task.front().first < now){
                    task.push(task.front());
                    task.pop();
                }
            }
            done.push(task.front());
            task.pop();
            sorted.pop();
        }
        int ans=0;
        while(!done.empty()){
            ans++;
            if(done.front().second == M)
                break;
            done.pop();
        }
        cout<<ans<< "\n";
    }
}