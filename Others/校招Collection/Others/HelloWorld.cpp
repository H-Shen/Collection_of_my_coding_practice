// https://ac.nowcoder.com/acm/problem/14835

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i % 6 == 0) {
            cout << "HelloWorld\n";
        } else if (i % 3 == 0) {
            cout << "World\n";
        } else if (i % 2 == 0) {
            cout << "Hello\n";
        } else {
            cout << i << '\n';
        }
    }

    return 0;
}