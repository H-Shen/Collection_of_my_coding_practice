// https://ac.nowcoder.com/acm/problem/15494

#include <string>
#include <iostream>
#include <cctype>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    ll cnt = 1;
    for (const auto &r : s)
    {
        if (r == '0' || r == 'O' || r == 'o')
        {
            cnt = cnt * 3 % MOD;
        }
        else if (r == 'I' || r == 'i' || r == 'l' || r == 'L')
        {
            cnt = cnt * 4 % MOD;
        }
        else if (isalpha(r))
        {
            cnt = cnt * 2 % MOD;
        }
    }
    cnt %= MOD;
    cout << cnt << endl;


    return 0;
}