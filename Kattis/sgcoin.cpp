// https://open.kattis.com/problems/sgcoin
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    ll v;
    ll token;
    string transaction = "a";

    scanf("%lld", &v);
    for (char i : transaction) {
        v = (v * 31 + i) % 1000000007;
    }
    if (7 * v < 10000000 + 1000000007) {
        token = 10000000 + 1000000007 - 7 * v;
    } else {
        ll k = 1;
        while (10000000 + 1000000007 * k - 7 * v < 0) {
            ++k;
        }
        token = 10000000 + 1000000007 * k - 7 * v;
    }
    printf("a %lld\na 839999342\n", token);

    return 0;
}
