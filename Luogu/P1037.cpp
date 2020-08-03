#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using int128 = __int128;

constexpr int MAX_NODES = 15;

inline
void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

inline
string print_int_128(int128 a) {
    if (!a) {
        return "0";
    }
    string s;
    while (a) {
        s = char(llabs((long long)(a % 10)) + '0') + s;
        if (a < 0 && a > -10) {
            s = '-' + s;
        }
        a /= 10;
    }
    return s;
}

template<size_t N>
struct TransitiveClosure {
    bitset<N> reach[N];
    void floyd_warshall(int n) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (reach[i][k]) {
                    reach[i] |= reach[k];    // reach[i] = reach[i] | reach[k];
                }
            }
        }
    }
    void reset() {
        for (int i = 0; i < N; ++i) {
            reach[i].reset();
        }
    }
};

TransitiveClosure<MAX_NODES> tc;

int main() {

    fast_io();
    string s;
    int k, u, v;
    cin >> s >> k;
    while (k--) {
        cin >> u >> v;
        tc.reach[u][v] = true;
    }
    // self to self
    for (int i = 0; i < MAX_NODES; ++i) {
        tc.reach[i][i] = true;
    }
    tc.floyd_warshall(MAX_NODES);
    int128 result = 1;
    int counter;
    int temp;
    for (const char &ch : s) {
        counter = 0;
        temp = ch - '0';
        for (int i = 0; i <= 9; ++i) {
            if (tc.reach[temp][i]) {
                ++counter;
            }
        }
        result = result * counter;
    }
    cout << print_int_128(result) << '\n';

    return 0;
}