#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 20;
char a[MAXN];
char b[MAXN];

unordered_map<string, pair<ll, ll> > A;

int main() {

    int n;
    scanf("%d", &n);
    string s, a_str, b_str;
    while (n--) {
        scanf("%s %s", a, b);
        a_str = string(a).substr(0, 2);
        b_str = string(b);
        if (a_str != b_str) {
            if (a_str > b_str) {
                swap(a_str, b_str);
                ++A[a_str + " " + b_str].second;
            } else {
                ++A[a_str + " " + b_str].first;
            }
        }
    }
    ll counter = 0;
    for (const auto &[k, v] : A) {
        counter += v.first * v.second;
    }
    printf("%lld\n", counter);

    return 0;
}