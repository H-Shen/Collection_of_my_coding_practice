#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

string printint128(__int128 a) { // prints as decimal
    if (!a) return "0";
    string s;
    while (a) {
        s = char(llabs(a % 10) + '0') + s;
        if (-10 < a && a < 0) s = '-' + s;
        a /= 10;
    }
    return s;
}

int main() {

    int n;
    ll c;
    ll val;
    unordered_map<ll, ll> A;
    scanf("%d %lld", &n, &c);
    while (n--) {
        scanf("%lld", &val);
        ++A[val];
    }
    __int128 counter = 0;
    ll a;
    ll b;
    for (const auto &i : A) {
        a = i.first;
        b = a - c;
        if (A.find(b) != A.end()) {
            if (a == b) {
                counter += i.second * (i.second - 1) / 2;
            } else {
                counter += i.second * A[b];
            }
        }
    }
    printf("%s\n", printint128(counter).c_str());

    return 0;
}
