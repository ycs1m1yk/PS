#include <cstdio>
#include <vector>

using namespace std;

vector<int> ans;
// f2 >= f1
vector<int> operator +(vector<int> &f2, vector<int> &f1){
    bool carry=false;
    vector<int> ret(f2.size(), 0);
    for(int i=0; i<f2.size(); i++){
        ret[i] = f2[i] + (i<f1.size()?f1[i]:0) + carry;
        if(ret[i]>=10){
            carry=true;
            ret[i]-=10;
        }
        else carry = false;
    }
    if(carry) ret.push_back(1);
    return ret;
}

int main(){
    int N;
    scanf("%d", &N);
    if(N<2){
        printf("%d", N);
        return 0;
    }
    vector<int> f1(1, 0), f2(1, 1), f3;
    for(int i=2; i<=N; i++){
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;
    }

    for(auto i=f2.rbegin(); i!=f2.rend(); ++i) printf("%d", *i);
}

