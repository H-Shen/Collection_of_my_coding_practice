#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 32;

int main() {

    ll n;
    scanf("%lld", &n);
    bitset<MAXN> A(n);
    string s = A.to_string();
    bitset<MAXN> B(s.substr(16) + s.substr(0, 16));
    printf("%llu\n", B.to_ullong());

    return 0;
}