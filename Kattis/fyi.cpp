// https://open.kattis.com/problems/fyi

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using int128 = __int128;
using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vi = vector<int>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {

    string s;
    cin >> s;
    if (s[0] == '5' && s[1] == '5' && s[2] == '5') cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}
