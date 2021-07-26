// https://open.kattis.com/problems/arithmeticdecoding

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

double my_stod(const string &s) {
    double res = 0;
    double a = 0.5;
    int n = (int)s.size();
    for (int i = 2; i < n; ++i) {
        if (s[i] == '1') {
            res += a;
        }
        a /= 2.0;
    }
    return res;
}

vector<int> ans;
bool f(vector<int> v, int n, double pa, double p) {
    constexpr double EPS = 1e-9;
    double a,b,c;
    do {
        a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            c = a+pa*(b-a);
            if (v[i] != 0) {
                a = c;
            }
            else {
                b = c;
            }
        }
        if (fabs(a - p) < EPS) {
            ans = v;
            return true;
        }
    } while (next_permutation(v.begin(), v.end()));
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, d;
    double pa, p;
    string s;
    cin >> n >> d >> s;
    pa = d / 8.0;
    p = my_stod(s);
    vector<int> v(n);
    if (f(v, n, pa, p)) {
        for (const auto &i : ans) {
            if (i != 0) cout << 'B';
            else cout << 'A';
        }
        return 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        v[i] = 1;
        if (f(v, n, pa, p)) {
            for (const auto &j : ans) {
                if (j != 0) cout << 'B';
                else cout << 'A';
            }
            return 0;
        }
    }
    return 0;
}

