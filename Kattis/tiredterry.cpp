// https://open.kattis.com/problems/tiredterry

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, p, d;
string s;
vector<int> pattern, pre;

int rangeSum(int l, int r) {
    if (l == 0) return pre.at(r);
    return pre.at(r) - pre.at(l - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> p >> d >> s;
    pattern.resize(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'Z') {
            pattern[i] = 1;
        }
    }
    pattern.resize(2 * n);
    for (int i = n; i < 2*n; ++i) {
        pattern.at(i) = pattern.at(i - n);
    }
    pre.resize(n * 2);
    partial_sum(pattern.begin(), pattern.end(), pre.begin());
    int counter = 0;
    for (int i = n; i < 2*n; ++i) {
        if (rangeSum(i - p + 1, i) < d) {
            ++counter;
        }
    }
    cout << counter << '\n';
    return 0;
}
