// https://open.kattis.com/problems/basketballoneonone
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    int A = 0, B = 0;
    cin >> s;
    bool turnOfA;
    bool tieByTenToTen = false;
    for (const char &ch : s) {
        if (ch == 'A') {
            turnOfA = true;
        } else if (ch == 'B') {
            turnOfA = false;
        } else {
            if (turnOfA) {
                A += static_cast<int>(ch - '0');
            } else {
                B += static_cast<int>(ch - '0');
            }
            if (A == 10 && B == 10) {
                tieByTenToTen = true;
            }
            if (tieByTenToTen) {
                if (A - B >= 2) {
                    cout << 'A' << endl;
                    return 0;
                } else if (B - A >= 2) {
                    cout << 'B' << endl;
                    return 0;
                }
            } else {
                if (A >= 11) {
                    cout << 'A' << endl;
                    return 0;
                } else if (B >= 11) {
                    cout << 'B' << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
