// https://ac.nowcoder.com/acm/problem/14398

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int T;
    int sum;
    cin >> T;
    string s;
    while (T--) {
        cin >> s;
        sum = 0;
        for (const auto &i : s) {
            sum += static_cast<int>(i - '0');
        }
        cout << sum << endl;
    }
    return 0;
}