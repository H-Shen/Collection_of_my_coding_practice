// https://open.kattis.com/problems/cocktail

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 1010000;
int diff[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<int> A(n);
    for (auto&i : A) cin >> i;
    sort(A.begin(),A.end(),greater<>());
    int l, r;
    int currentTime = 0;
    for (int i = 0; i < n; ++i) {
        currentTime += t;
        l = currentTime + 1;
        r = l + A[i] - 1;
        ++diff[l];
        --diff[r+1];
    }
    for (int i = 1; i < MAXN; ++i) {
        diff[i] += diff[i-1];
        if (diff[i] == n) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}
