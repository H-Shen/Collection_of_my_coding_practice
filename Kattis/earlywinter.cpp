// https://open.kattis.com/problems/earlywinter
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, d_m, d_i;
    cin >> n >> d_m;

    int i = 0;
    for (; i < n; ++i) {
        cin >> d_i;
        if (d_i <= d_m) {
            cout << "It hadn't snowed this early in " << i << " years!" << endl;
            return 0;
        }
    }
    cout << "It had never snowed this early!" << endl;

    return 0;
}
