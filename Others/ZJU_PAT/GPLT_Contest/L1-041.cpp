#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    int n = 0, res = -1;
    while (cin >> num) {
        ++n;
        if (num == 250 && res == -1) {
            res = n;
        }
    }
    cout << res << endl;
    return 0;
}