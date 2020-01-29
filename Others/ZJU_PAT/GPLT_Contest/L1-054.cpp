#include <bits/stdc++.h>

using namespace std;

vector<string> myReverse(vector<string> A) {
    reverse(A.begin(), A.end());
    for (auto &&r : A) {
        reverse(r.begin(), r.end());
    }
    return A;
}

int main() {
    string chr;
    int n;
    cin >> chr >> n;
    vector<string> A(n);
    getchar();

    for (auto &&r : A) {
        getline(cin, r);
    }

    vector<string> ans = myReverse(A);
    if (ans == A) {
        cout << "bu yong dao le" << endl;
    }
    for (const auto &r : ans) {
        for (const auto &rr : r) {
            if (rr == '@') {
                cout << chr;
            } else {
                cout << rr;
            }
        }
        cout << endl;
    }

    return 0;

}