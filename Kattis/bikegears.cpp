// https://open.kattis.com/problems/bikegears
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct Node {
    ll a;
    ll b;
    Node(ll a, ll b) : a(a), b(b) {}
};

bool cmp(const Node &l, const Node &r) {
    // l.a / l.b == r.a / r.b
    if (l.a * r.b == r.a * l.b) {
        return l.a < r.a;
    }
    // l.a / l.b < r.a / r.b
    // l.a < r.a / r.b * l.b
    // l.a * r.b < r.a * l.b
    return l.a * r.b < r.a * l.b;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<ll> A(n);
    for (auto &i : A) {
        scanf("%lld", &i);
    }
    vector<ll> B(m);
    for (auto &i : B) {
        scanf("%lld", &i);
    }
    vector<Node> C;
    for (const auto &i : A) {
        for (const auto &j : B) {
            C.emplace_back(Node(i, j));
        }
    }
    sort(C.begin(), C.end(), cmp);
    for (const auto &[k, v] : C) {
        printf("(%lld,%lld)\n", k, v);
    }

    return 0;
}
