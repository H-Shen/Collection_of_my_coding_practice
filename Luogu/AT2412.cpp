#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

vector<ll> A, pre;

ll rangeSum(int l, int r) {
    if (l == 0) return pre.at(r);
    return pre.at(r) - pre.at(l - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    A.resize(n);
    pre.resize(n);
    for (auto &i : A) cin >> i;
    partial_sum(A.begin(), A.end(), pre.begin());
    ll maxVal = -1;
    for (int i = 0; i < n - k; ++i) {
        maxVal = max(maxVal, rangeSum(i, i + k - 1));
    }
    cout << maxVal << '\n';

    return 0;
}