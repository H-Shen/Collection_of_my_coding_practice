// https://open.kattis.com/problems/divvyingup

#include <bits/extc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    ull sum = 0;
    ull val;
    while (n--) {
        cin >> val;
        sum += val;
    }
    if (sum % 3 == 0) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}
