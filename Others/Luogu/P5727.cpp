#include <bits/stdc++.h>

using namespace std;

vector<int> A;

void solve(int n) {
    if (n == 1) {
        A.emplace_back(1);
        return;
    }
    if (n % 2 == 0) {
        A.emplace_back(n);
        solve(n / 2);
    } else {
        A.emplace_back(n);
        solve(3 * n + 1);
    }
}

int main() {

    int n;
    cin >> n;
    solve(n);
    bool firstItem = true;
    for (auto it = A.rbegin(); it != A.rend(); ++it) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ' ';
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}