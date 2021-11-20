// https://open.kattis.com/problems/fairplay

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
ll sum_a, sum_b;

struct myHashFunc {
    size_t operator()(const pair<ll,ll> &o) const {
        return hash<ll>()(o.first) ^ hash<ll>()(o.second);
    }
};

unordered_map<pair<ll,ll>,ll,myHashFunc> stats;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    pair<ll,ll> p;
    for (ll i = 0; i < n; ++i) {
        cin >> p.first >> p.second;
        sum_a += p.first;
        sum_b += p.second;
        ++stats[p];
    }
    if ((sum_a * 2) % n != 0 || (sum_b * 2) % n != 0) {
        cout << "impossible" << '\n';
        return 0;
    }
    ll temp_a = sum_a * 2 / n;
    ll temp_b = sum_b * 2 / n;
    while (!stats.empty()) {
        auto node = stats.begin()->first;
        p.first = temp_a - node.first;
        p.second = temp_b - node.second;
        if (node == p) {
            if (stats[p] % 2 == 0) {
                stats.erase(p);
            } else {
                cout << "impossible" << '\n';
                return 0;
            }
        }
        else {
            if (stats.find(p) == stats.end() || stats[node] != stats[p]) {
                cout << "impossible" << '\n';
                return 0;
            }
            else {
                stats.erase(node);
                stats.erase(p);
            }
        }
    }
    cout << "possible" << '\n';
    return 0;
}
