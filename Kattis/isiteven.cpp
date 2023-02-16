// https://open.kattis.com/problems/isiteven


#include <bits/stdc++.h>

using namespace std;

int n,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    vector<int> evens;
    int val;
    while (n--) {
        cin >> val;
        if (!(val & 1)) {
            evens.emplace_back(val);
        }
    }
    if (k == 0) {
        cout << 1 << '\n';
        return 0;
    }
    while (k > 0) {
        if (evens.empty()) {
            cout << 0 << '\n';
            return 0;
        }
        else {
            if (evens.back() % 2 == 0) {
                evens.back() >>= 1;
                --k;
            }
            else {
                evens.pop_back();
            }
        }
    }
    cout << 1 << '\n';
    return 0;
}
