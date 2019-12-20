// https://ac.nowcoder.com/acm/problem/15755

#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, n;
    bool isLegal = true;

    while (cin >> n) {
        A = 1;
        B = 2;
        C = 3;
        isLegal = true;
        vector<int> S(n);
        for (auto &&i : S) {
            cin >> i;
        }
        for (const auto &i : S) {
            if (C == i) {
                isLegal = false;
                break;
            }
            if (A == i) {
                swap(B, C);
            } else {
                swap(A, C);
            }
        }
        if (isLegal) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}