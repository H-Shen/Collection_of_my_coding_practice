// https://open.kattis.com/problems/rollcall
//
#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 20;
char s[maxn];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, string> > A;
    unordered_map<string, int> firstName2People;

    string firstName, lastName;
    while (cin >> firstName) {
        cin >> lastName;
        A.emplace_back(make_pair(firstName, lastName));
        ++firstName2People[firstName];
    }
    sort(A.begin(), A.end(), [](const pair<string, string> &lhs, const pair<string, string> &rhs)
    {
        if (lhs.second == rhs.second) {
            return (lhs.first < rhs.first);
        }
        return (lhs.second < rhs.second);
    });

    // output
    for (const auto &i : A) {
        if (firstName2People[i.first] > 1) {
            cout << i.first << ' ' << i.second << endl;
        } else {
            cout << i.first << endl;
        }
    }

    return 0;
}
