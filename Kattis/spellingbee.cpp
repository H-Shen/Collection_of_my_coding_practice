// https://open.kattis.com/problems/spellingbee

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

constexpr int MAXN = 30;
bitset<MAXN> exist;

bool check(const string &str, char c) {
    if (str.size() < 4) return false;
    bool containCenterLetter = false;
    for (const auto &ch : str) {
        if (!exist[ch - 'a']) {
            return false;
        }
        if (ch == c) {
            containCenterLetter = true;
        }
    }
    if (containCenterLetter) return true;
    return false;
}

int main() {

    fast_io();
    string s, s1;
    cin >> s;
    char centerLetter = s.front();
    for (const auto &i : s) {
        exist[i - 'a'] = true;
    }
    int n;
    cin >> n;
    while (n--) {
        cin >> s1;
        if (check(s1, centerLetter)) {
            cout << s1 << '\n';
        }
    }
    return 0;
}
