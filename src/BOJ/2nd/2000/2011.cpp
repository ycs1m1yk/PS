#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 5001;
const int MOD = 1000000;
/*
        암호가 잘못되어 암호를 해석할 수 없는 경우에는 0을 출력한다.
        0이 입력되는경우 주의!!, bottom-up이 유리함.
    */
string cipher;
int cache[MAX];

int get_decryption_case(int pos)
{
    if (!cipher[pos])
        return 1;
    int &ret = cache[pos];
    if (ret != -1)
        return ret;
    if (cipher[pos] == '0')
        return 0;

    ret = get_decryption_case(pos + 1);
    if (cipher[pos] == '1' && cipher[pos + 1])
        ret = (ret + get_decryption_case(pos + 2)) % MOD;
    else if (cipher[pos] == '2' && cipher[pos + 1] && cipher[pos + 1] <= '6')
        ret = (ret + get_decryption_case(pos + 2)) % MOD;
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> cipher;
    cout << get_decryption_case(0);
}
