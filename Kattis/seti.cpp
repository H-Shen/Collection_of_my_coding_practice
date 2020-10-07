// https://open.kattis.com/problems/seti
// Gauss elimination with modulo
// 
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace GaussElimination {
    constexpr int MAXN = 80;
    constexpr ll INF = 0x3f3f3f3f;
    ll mod;
    ll augmentedMatrix[MAXN][MAXN];
    ll solutions[MAXN];

    void reset() {
        for (auto &i : augmentedMatrix) {
            fill(i, i + MAXN, 0);
        }
        fill(solutions, solutions + MAXN, 0);
    }

    ll inv(ll a, ll m) {
        if (a == 1) {
            return 1;
        }
        return inv(m % a, m) * (m - m / a) % m;
    }

    ll gauss(ll equation, ll variable) {
        ll max_r, col, k;
        for (k = 0, col = 0; k < equation && col < variable; ++k, ++col) {
            max_r = k;
            for (ll i = k + 1; i < equation; ++i) {
                if (abs(augmentedMatrix[i][col]) >
                    abs(augmentedMatrix[max_r][col])) {
                    max_r = i;
                }
            }
            if (augmentedMatrix[max_r][col] == 0) {
                --k;
                continue;
            }
            if (max_r != k) {
                for (ll j = col; j < variable + 1; ++j) {
                    swap(augmentedMatrix[k][j], augmentedMatrix[max_r][j]);
                }
            }
            for (ll i = k + 1; i < equation; ++i) {
                if (augmentedMatrix[i][col] != 0) {
                    ll lcm_ = lcm(abs(augmentedMatrix[i][col]),
                                  abs(augmentedMatrix[k][col]));
                    ll ta = lcm_ / abs(augmentedMatrix[i][col]);
                    ll tb = lcm_ / abs(augmentedMatrix[k][col]);
                    if (augmentedMatrix[i][col] * augmentedMatrix[k][col] < 0) {
                        tb = -tb;
                    }
                    for (ll j = col; j < variable + 1; ++j) {
                        augmentedMatrix[i][j] = ((augmentedMatrix[i][j] * ta -
                                                  augmentedMatrix[k][j] * tb) %
                                                 mod + mod) % mod;
                    }
                }
            }
        }
        for (ll i = k; i < equation; ++i) {
            if (augmentedMatrix[i][col] != 0) {
                return -1;  // no solutions
            }
        }
        if (k < variable) {
            return INF; // inf solutions
        }
        for (ll i = variable - 1; i >= 0; --i) {
            ll temp = augmentedMatrix[i][variable];
            for (ll j = i + 1; j < variable; ++j) {
                if (augmentedMatrix[i][j] != 0) {
                    temp -= augmentedMatrix[i][j] * solutions[j];
                    temp = (temp % mod + mod) % mod;
                }
            }
            solutions[i] = (temp * inv(augmentedMatrix[i][i], mod)) % mod;
        }
        return 1;   // one solution
    }
}

ll convert(char ch) {
    if (ch == '*') return 0;
    return (ch - 'a' + 1);
}

ll modpow(ll a, ll p, ll M) {
    if (M == 1) return 0;
    ll r;
    for (r = 1, a %= M; p; a = (a * a) % M, p >>= 1) if (p % 2) r = (r * a) % M;
    return r;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    string s;
    ll n;
    cin >> t;
    while (t--) {
        cin >> GaussElimination::mod >> s;
        n = s.size();
        // right side of the augmented matrix
        for (int i = 0; i < n; ++i) {
            GaussElimination::augmentedMatrix[i][n] =
                    convert(s.at(i)) % GaussElimination::mod;
        }
        // left side of the augmented matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                GaussElimination::augmentedMatrix[i][j] = modpow(i + 1, j,
                                                                 GaussElimination::mod);
            }
        }
        ll solutions = GaussElimination::gauss(n, n);
        for (int i = 0; i < n; ++i) {
            cout << GaussElimination::solutions[i];
            if (i == n - 1) {
                cout << '\n';
            } else {
                cout << ' ';
            }
        }
        GaussElimination::reset();
    }
    return 0;
}
