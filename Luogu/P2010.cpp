#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline bool is_leap(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

inline bool check(int y, const string& s) {
    int m = stoi(s.substr(4, 2));
    int d = stoi(s.substr(6));
    if (m > 12 || m == 0 || d == 0) return false;
    if (is_leap(y) && m == 2 && d > 29) {
        return false;
    }
    if (!is_leap(y) && m == 2 && d > 28) {
        return false;
    }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 31) return false;
    }
    else {
        if (d > 30) return false;
    }
    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    string a, b;
    int temp;
    for (int i = 1000; i <= 9999; ++i) {
        a = to_string(i);
        b = a;
        reverse(b.begin(),b.end());
        a += b;
        if (check(i, a)) {
            temp = stoi(a);
            if (temp >= l && temp <= r) {
                ++cnt;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
