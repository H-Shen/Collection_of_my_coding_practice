// https://open.kattis.com/problems/multigram

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 26;
bitset<MAXN> vis;
vector<int> factors;
int stats[MAXN];

bool check() {
    for (int i = 0; i < MAXN; ++i) {
        if (vis[i] && stats[i] == 0) {
            return false;
        }
    }
    return true;
}

bool check2(const string &s, int length, int n) {
    for (int i = length, j = length*2 - 1; i < n; i += length, j += length) {
        int stats2[MAXN]{};
        for (int k = i; k <= j; ++k) {
            ++stats2[s[k] - 'a'];
        }
        for (int k = 0; k < MAXN; ++k) {
            if (stats2[k] != stats[k]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();
    if (n <= 1) {
        cout << -1 << '\n';
        return 0;
    }
    factors.emplace_back(1);
    for (const auto &ch : s) vis[ch - 'a'] = true;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            factors.emplace_back(i);
            if (i*i != n) {
                factors.emplace_back(n/i);
            }
        }
    }
    sort(factors.begin(),  factors.end());
    int length = 0;
    for (const auto &i : factors) {
        while (length < i) {
            ++stats[s[length] - 'a'];
            ++length;
        }
        if (check() && check2(s, length, n)) {
            for (int j = 0; j < length; ++j) {
                cout << s[j];
            }
            cout << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
