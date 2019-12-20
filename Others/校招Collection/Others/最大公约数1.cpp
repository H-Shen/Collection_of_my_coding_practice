// https://www.nowcoder.com/practice/021010dda9f04900a86738931a5600a4

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef __GNUC__
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        vector<int> A(static_cast<unsigned long>(n));
        for (auto &&i : A) {
            cin >> i;
        }
        auto minVal = *min_element(A.begin(), A.end());
        auto maxVal = *max_element(A.begin(), A.end());
        auto gcdVal = __gcd(minVal, maxVal);
        cout << minVal << ' ';
        cout << maxVal << ' ';
        cout << gcdVal << endl;
    }
#endif
    return 0;
}