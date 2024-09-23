#include <bits/stdc++.h>

using namespace std;

int main() {

    int L0, L1, L0_copy, L1_copy, n;
    cin >> L0 >> L1 >> n;
    L0_copy = L0;
    L1_copy = L1;

    int s, V0, V1, A0, A1;
    while (n--) {
        cin >> V0 >> A0 >> V1 >> A1;
        s = V0 + V1;

        if (A0 != s && A1 != s) {
            continue;
        }
        if (A0 == s && A1 == s) {
            continue;
        }

        if (A0 == s && A1 != s) {
            --L0;
        } else {
            --L1;
        }

        if (L0 == -1) {
            cout << "A" << endl;
            cout << L1_copy - L1 << endl;
            break;
        }
        if (L1 == -1) {
            cout << "B" << endl;
            cout << L0_copy - L0 << endl;
            break;
        }
    }

    return 0;
}