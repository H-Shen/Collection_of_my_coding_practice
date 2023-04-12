// https://open.kattis.com/problems/99problems2
//
#include <bits/stdc++.h>

using namespace std;

int n, q, t, d;
multiset<int> ms;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    multiset<int>::iterator iter;
    while (n--) {
        cin >> d;
        ms.insert(d);
    }
    while (q--) {
        cin >> t >> d;
        if (t == 1) {
            iter = ms.upper_bound(d);
            if (iter == ms.end()) {
                cout << -1 << '\n';
            }
            else {
                cout << *iter << '\n';
                ms.erase(iter);
            }
        }
        else {
            if (ms.empty() || *ms.begin() > d) {
                cout << -1 << '\n';
            }
            else {
                iter = --ms.upper_bound(d);
                cout << *iter << '\n';
                ms.erase(iter);
            }
        }
    }
    return 0;
}
