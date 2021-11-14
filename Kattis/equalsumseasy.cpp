// https://open.kattis.com/problems/equalsumseasy

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 25;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n, tol, temp, sum, index;
    bool haveAns;
    int first, second;
    cin >> t;
    for (int kase = 1; kase <= t; ++kase) {
        cin >> n;
        vector<int> A(n);
        for (auto&i : A) cin >> i;
        unordered_map<int,vector<int>> unmap;
        tol = (1<<n);
        haveAns = false;
        for (int i = 1; i < tol; ++i) {
            sum = 0;
            temp = i;
            index = 0;
            while (temp > 0) {
                if (temp & 1) {
                    sum += A[index];
                }
                ++index;
                temp >>= 1;
            }
            auto iter = unmap.find(sum);
            if (iter != unmap.end()) {
                for (auto& j : iter->second) {
                    if (!(i & j)) {
                        first = i;
                        second = j;
                        haveAns = true;
                        break;
                    }
                }
            }
            unmap[sum].emplace_back(i);
            if (haveAns) {
                break;
            }
        }
        cout << "Case #" << kase << ":\n";
        if (haveAns) {
            bitset<MAXN> bs1(first);
            for (int pos = 0; pos < n; ++pos) {
                if (bs1[pos]) {
                    cout << A[pos] << ' ';
                }
            }
            cout << '\n';
            bitset<MAXN> bs2(second);
            for (int pos = 0; pos < n; ++pos) {
                if (bs2[pos]) {
                    cout << A[pos] << ' ';
                }
            }
            cout << '\n';
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}
