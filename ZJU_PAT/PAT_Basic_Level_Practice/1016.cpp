#include <bits/stdc++.h>

using namespace std;

int main() {
    string A, B, strA, strB;
    char D_A, D_B;
    cin >> A >> D_A >> B >> D_B;
    for (auto &i : A) {
        if (i == D_A) {
            strA += i;
        }
    }
    for (auto &i : B) {
        if (i == D_B) {
            strB += i;
        }
    }

    long long aVal, bVal;

    if (strA == "") {
        aVal = 0;
    } else {
        aVal = stol(strA);
    }

    if (strB == "") {
        bVal = 0;
    } else {
        bVal = stol(strB);
    }

    cout << aVal + bVal << endl;
    return 0;
}