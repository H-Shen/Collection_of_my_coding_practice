// https://open.kattis.com/problems/oddecho

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        if (i & 1) cout << s << '\n';
    }
    return 0;
}
