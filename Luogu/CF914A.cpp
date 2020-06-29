#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 1000000;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_set<int, custom_hash> unset;
    int n = 0;
    int n_sqaure;
    do {
        n_sqaure = n * n;
        unset.insert(n_sqaure);
        ++n;
    } while (n_sqaure <= MAXN);
    int m, val;
    cin >> m;
    int max_val = numeric_limits<int>::min();
    while (m--) {
        cin >> val;
        if (unset.find(val) == unset.end()) {
            max_val = max(max_val, val);
        }
    }
    cout << max_val << '\n';


    return 0;
}
