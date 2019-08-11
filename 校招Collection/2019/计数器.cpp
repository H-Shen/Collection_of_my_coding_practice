// https://www.nowcoder.com/practice/e953b0dc87bb43f29cb042c7a9f31598

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MAXN = 1000000000005;

int main() {

    ios_base::sync_with_stdio(false);
    vector<ll> A{2};
    while (A.back() < MAXN) {
        A.emplace_back(A.back() * 2);
    }

    ll t;
    ll maxVal{-1};
    cin >> t;
    if (t <= 3) {
        maxVal = 3;
    } else {
        int len = static_cast<int>(A.size());
        for (int i = 0; i < len - 1; ++i) {
            if (3 * (A.at(i) - 1) < t && t <= 3 * (A.at(i + 1) - 1)) {
                maxVal = 3 * (A.at(i + 1) - 1);
                break;
            }
        }
    }
    cout << maxVal + 1 - t << endl;

    return 0;
}