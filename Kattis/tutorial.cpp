// https://open.kattis.com/problems/tutorial
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MAXN = 7000000005;
constexpr double EPS = 1e-6;

vector<ll> factorial{1, 1};
vector<ll> powerOfTwo = {1};

inline static
int sgn(const double &a) {
    if (a > EPS) {
        return 1;
    }
    if (a > -EPS) {
        return 0;
    }
    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // pre
    while (factorial.back() < MAXN) {
        factorial.emplace_back(factorial.back() * static_cast<ll>(factorial.size()));
    }
    while (powerOfTwo.back() < MAXN) {
        powerOfTwo.emplace_back(powerOfTwo.back() * 2);
    }
    // input
    int type;
    ll m, n;
    cin >> m >> n >> type;
    __int128 m_int128 = m;
    __int128 n_int128 = n;

    bool ac = false;
    int length;
    switch (type) {
        case 7:
            if (n <= m) {
                ac = true;
            }
            break;
        case 6:
            if (sgn(static_cast<double>(n*log2(n)) - static_cast<double>(m)) <= 0) {
                ac = true;
            }
            break;
        case 5:
            if (n_int128 * n_int128 <= m_int128) {
                ac = true;
            }
            break;
        case 4:
            if (n_int128 * n_int128 * n_int128 <= m_int128) {
                ac = true;
            }
            break;
        case 3:
            if (n_int128 * n_int128 * n_int128 * n_int128 <= m_int128) {
                ac = true;
            }
            break;
        case 2:
            // compare 2^n and upper
            length = static_cast<int>(powerOfTwo.size());
            for (int i = 0; i < length; ++i) {
                if (powerOfTwo.at(i) > m) {
                    if (n <= i - 1) {
                        ac = true;
                    }
                    break;
                }
            }
            break;
        default:
            // compare n! and upper
            length = static_cast<int>(factorial.size());
            for (int i = 0; i < length; ++i) {
                if (factorial.at(i) > m) {
                    if (n <= i - 1) {
                        ac = true;
                    }
                    break;
                }
            }
            break;
    }

    // output
    if (ac) {
        cout << "AC";
    } else {
        cout << "TLE";
    }
    cout << '\n';

    return 0;
}
