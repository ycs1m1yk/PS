#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

long long getUpperBound(int n)
{
    long long ret = 1;
    int range = min(n, N);
    for (int i = 1; i <= range; i++)    
        ret += min((int)(n / i), range);    

    return ret;
}

long long binarySearch(){
    long long left=1, right = min((long long)N*N, 1000000000LL);
    while(left < right){
        int mid = (left + right)/2;     
        // lower bound
        if(getUpperBound(mid)-1 < K)
            left = mid+1;
        else
            right = mid;
    }

    return (left+right)/2;
}

int main()
{
    cin >> N >> K;

    cout << binarySearch();  

}