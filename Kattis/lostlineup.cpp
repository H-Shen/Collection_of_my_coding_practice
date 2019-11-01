// https://open.kattis.com/problems/lostlineup
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<pair<int, int> > distance2Id;
    int n, dist;
    cin >> n;
    if (n == 1) {
        // output
        cout << 1 << endl;
    } else {
        for (int i = 2; i <= n; ++i) {
            cin >> dist;
            distance2Id.emplace_back(make_pair(dist, i));
        }
        // sort
        sort(distance2Id.begin(), distance2Id.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return (a.first < b.first);
        });
        // output
        cout << 1;
        for (const auto &i : distance2Id) {
            cout << ' ' << i.second;
        }
        cout << endl;
    }

    return 0;
}
