// https://open.kattis.com/problems/sortofsorting

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string s;
    bool firstCase = true;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<pair<string, int> > A(n);
        for (int i = 0; i < n; ++i) {
            cin >> s;
            A.at(i) = make_pair(s, i);
        }
        sort(A.begin(), A.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs)
        {
            if (lhs.first.length() >= 2 && rhs.first.length() >= 2) {
                if (lhs.first.substr(0, 2) == rhs.first.substr(0, 2)) {
                    return lhs.second < rhs.second;
                }
            }
            return lhs.first < rhs.first;
        });
        if (firstCase) {
            firstCase = false;
        } else {
            cout << endl;
        }
        for (const auto &i : A) {
            cout << i.first << endl;
        }
    }

    return 0;
}
