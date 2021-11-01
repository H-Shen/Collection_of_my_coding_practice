// https://open.kattis.com/problems/compromise

#include <bits/extc++.h>

using ll = long long;
using namespace std;

int t, n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<string> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        string ans;
        ans.resize(m);
        for (int i = 0; i < m; ++i) {
            int counter0 = 0, counter1 = 0;
            for (int j = 0; j < n; ++j) {
                if (vec[j][i] == '0') {
                    ++counter0;
                } else {
                    ++counter1;
                }
            }
            ans[i] = (counter0 > counter1) ? '0' : '1';
        }
        cout << ans << '\n';
    }
    return 0;
}
