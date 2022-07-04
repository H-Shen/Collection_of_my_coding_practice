#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int a, b;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (5*a-3*b > 40) ++counter;
    }
    cout << counter;
    if (counter == n) cout << '+';
    cout << '\n';
    return 0;
}