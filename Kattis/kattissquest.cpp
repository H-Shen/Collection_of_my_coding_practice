// https://open.kattis.com/problems/kattissquest
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 10;
char op[MAXN];

int main() {

    int n;
    ll e, g, x, x_, g_;
    scanf("%d", &n);
    map<ll, priority_queue<ll, vector<ll>, less<> > > x2g;
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "add") == 0) {
            scanf("%lld %lld", &e, &g);
            x2g[e].push(g);
        } else {
            scanf("%lld", &x);
            ll gold = 0;
            while (true) {
                if (x2g.empty()) {
                    break;
                }
                if (x < x2g.begin()->first) {
                    break;
                } else if (x > x2g.rbegin()->first) {
                    x_ = x2g.rbegin()->first;
                } else {
                    auto temp_iter = x2g.lower_bound(x);
                    if (temp_iter->first == x) {
                        x_ = x;
                    } else {
                        x_ = (--temp_iter)->first;
                    }
                }
                g_ = x2g[x_].top();
                x2g[x_].pop();
                if (x2g[x_].empty()) {
                    x2g.erase(x_);
                }
                x -= x_;
                gold += g_;
            }
            printf("%lld\n", gold);

        }
    }
    return 0;
}
