#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long s;
    while (cin >> s) {
        if (s == 0)
            break;
        cout << 3 * static_cast<long long>(pow(2.0, static_cast<double>(s - 1))) - 2 << endl;
    }
    return 0;
}