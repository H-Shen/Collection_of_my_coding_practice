#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int cnt = 0;
    cin >> n;
    while (true) {
        if (n == 1) {
            break;
        }
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
            n /= 2;
        }
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}