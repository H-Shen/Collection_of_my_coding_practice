// https://open.kattis.com/problems/electionparadox

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    A.resize(n);
    for (auto&i : A) cin >> i;
    sort(A.begin(),A.end(), greater<>());
    int counter = 0;
    int win = n / 2;
    int i = 0;
    for (; i < win; ++i) {
        counter += A[i];
    }
    for (; i < n; ++i) {
        counter += A[i] / 2;
    }
    cout << counter << '\n';
    return 0;
}
