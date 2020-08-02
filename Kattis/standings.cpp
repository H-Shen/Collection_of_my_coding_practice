// https://open.kattis.com/problems/standings
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {

    fast_io();
    int t, n;
    ll counter;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<string, int> > A(n);
        for (auto &[k, v] : A) {
            cin >> k >> v;
        }
        sort(A.begin(), A.end(), [](const pair<string, int> &l, const pair<string, int> &r){
            return (l.second < r.second);
        });
        counter = 0;
        for (int i = 0; i < n; ++i) {
            counter += abs(A.at(i).second - (i + 1));
        }
        cout << counter << '\n';
    }
    return 0;
}
