// https://open.kattis.com/problems/treeshopping

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &i : A) cin >> i;
    multiset<int> ms;
    for (int i = 0; i < k; ++i) {
        ms.insert(A[i]);
    }
    int minDiff = (*ms.rbegin()) - (*ms.begin());
    for (int i = k, j = 0; i < n; ++i, ++j) {
        ms.erase(ms.find(A[j]));
        ms.insert(A[i]);
        minDiff = min(minDiff, (*ms.rbegin()) - (*ms.begin()));
    }
    cout << minDiff << '\n';
    return 0;
}
