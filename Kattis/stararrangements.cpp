// https://open.kattis.com/problems/stararrangements
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int S, a, b;
    cin >> S;

    vector<pair<int, int> > a_b;
    for (a = 2; a < S; ++a) {
        b = a;
        if (S % (a + b) == 0) {
            a_b.emplace_back(make_pair(a, b));
        }
        if ((S + b) % (a + b) == 0) {
            a_b.emplace_back(make_pair(a, b));
        }
        b = a - 1;
        if (S % (a + b) == 0) {
            a_b.emplace_back(make_pair(a, b));
        }
        if ((S + b) % (a + b) == 0) {
            a_b.emplace_back(make_pair(a, b));
        }
    }
    sort(begin(a_b), end(a_b), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        if (lhs.first == rhs.first) {
            return (lhs.second < rhs.second);
        }
        return (lhs.first < rhs.first);
    });
    cout << S << ":" << endl;
    for (const auto &i : a_b) {
        cout << i.first << "," << i.second << endl;
    }

    return 0;
}
