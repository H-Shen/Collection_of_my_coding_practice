// https://open.kattis.com/problems/fieldtrip

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    vector<ll> A, preLeft, preRight;
    cin >> n;
    A.resize(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        sum += A[i];
    }
    if (sum % 3 != 0) {
        cout << -1 << '\n';
        return 0;
    }
    sum /= 3;
    preLeft.resize(n);
    preLeft[0] = A[0];
    for (int i = 1; i < n; ++i) {
        preLeft[i] = preLeft[i-1] + A[i];
    }
    preRight.resize(n);
    preRight[0] = A[n-1];
    for (int i = n-2, j = 1; i >= 0; --i, ++j) {
        preRight[j] = preRight[j-1] + A[i];
    }
    if (!binary_search(preLeft.begin(),preLeft.end(),sum)) {
        cout << -1 << '\n';
        return 0;
    }
    int posLeft = (int)(lower_bound(preLeft.begin(),preLeft.end(),sum)-preLeft.begin())+1;
    if (!binary_search(preRight.begin(),preRight.end(),sum)) {
        cout << -1 << '\n';
        return 0;
    }
    int posRight = n-(int)(lower_bound(preRight.begin(),preRight.end(),sum)-preRight.begin())-1;
    cout << posLeft << ' ' << posRight << '\n';
    return 0;
}
