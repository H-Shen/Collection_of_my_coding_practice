// https://open.kattis.com/problems/magicalrunes 

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

// A:0 B:1
void upd(string&s) {
    vector<bool> update(s.size(), false);
    if (s[0] == '1') {
        s[0] = '0';
    } else {
        s[0] = '1';
    }
    update[0] = true;
    for (int i = 1; i < (int)s.size(); ++i) {
        if (update[i-1] && s[i-1] == '0') {
            update[i] = true;
            if (s[i] == '1') {
                s[i] = '0';
            }
            else {
                s[i] = '1';
            }
        }
    }
}

int main() {
    string s;
    ull d;
    cin >> s >> d;
    ull mod = 1ULL<<s.size();
    string p = s;
    reverse(p.begin(), p.end());
    for (auto&ch : p) {
        if (ch == 'A') {
            ch = '0';
        }
        else {
            ch = '1';
        }
    }
    constexpr int N = 35;
    bitset<N> bs(p);
    ull val = bs.to_ullong();
    val = (val + d) % mod;
    bitset<N> bs2(val);
    for (int i = (int)p.size()-1, j = 0; i >= 0; --i, ++j) {
        if (bs2[j]) {
            p[i] = 'B';
        }
        else {
            p[i] = 'A';
        }
    }
    reverse(p.begin(),p.end());
    cout << p << '\n';
    return 0;
}
