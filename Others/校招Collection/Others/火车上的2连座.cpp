// https://ac.nowcoder.com/acm/problem/15758

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    bool haveChange = false;

    while (cin >> n) {
        haveChange = false;
        vector<string> A(n);
        for (auto &&i : A) {
            cin >> i;
            if (!haveChange) {
                if (i[0] == 'O' && i[1] == 'O') {
                    i[0] = '+';
                    i[1] = '+';
                    haveChange = true;
                } else if (i[3] == 'O' && i[4] == 'O') {
                    i[3] = '+';
                    i[4] = '+';
                    haveChange = true;
                }
            }
        }

        if (haveChange) {
            cout << "YES" << endl;
            for (const auto &i : A) {
                cout << i << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}