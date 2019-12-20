// https://ac.nowcoder.com/acm/problem/15079

#include <iostream>

using namespace std;
using ll = long long;

ll n;

ll P(ll m)
{
    return n / m;
}

int main()
{
    ll cnt = 0;
    while (cin >> n) {
        cnt = P(2) + P(5) + P(11) + P(13) - P(2 * 5) - P(2 * 11) - P(2 * 13) - P(5 * 11) - P(5 * 13) - P(11 * 13) + P(2 * 5 * 11) + P(2 * 5 * 13) + P(2 * 11 * 13) + P(5 * 11 * 13) - P(2 * 5 * 11 * 13);
        cout << n - cnt << endl;
    }

    return 0;
}