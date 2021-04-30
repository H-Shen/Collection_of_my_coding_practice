#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {

    fast_io();
    int kase = 1;
    int n, m, val, result;
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<int> A(n);
        for (auto &i : A) cin >> i;
        unordered_set<int> unset;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i+1; j < n; ++j) {
                unset.insert(A[i]+A[j]);
            }
        }
        vector<int> B(unset.size());
        auto iter = B.begin();
        for (const auto &i : unset) {
            *iter = i;
            ++iter;
        }
        sort(B.begin(), B.end());
        cout << "Case " << kase << ":" << '\n';
        ++kase;
        cin >> m;
        while (m--) {
            cin >> val;
            if (val <= B.front()) {
                result = B.front();
            } else if (val >= B.back()) {
                result = B.back();
            } else {
                auto it = upper_bound(B.begin(), B.end(), val);
                int sum0 = *it;
                int diff0 = abs(sum0 - val);
                --it;
                int sum1 = *it;
                int diff1 = abs(sum1 - val);
                if (diff0 > diff1) {
                    result = sum1;
                } else {
                    result = sum0;
                }
            }
            cout << "Closest sum to " << val << " is " << result << ".\n";
        }
    }

    return 0;
}