#include <iostream>
#include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0)
typedef long long ll; 

int N, input;
priority_queue<ll> pq;

int main() {
    fastio;
    cin>>N;
    while(N--){
        cin>>input;
        if(input){
            pq.push(input);
        }
        else {
            if(pq.empty()) cout<<"0\n";
            else {cout<<pq.top()<<"\n"; pq.pop();}
        }
    }
    return 0;
}