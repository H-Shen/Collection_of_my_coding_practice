#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> A = {a, b, c};
    sort(A.begin(), A.end());
    int i;
    for (i = 0; i < 2; ++i) {
        cout << A[i] << "->";
    }
    cout << A[2] << endl;
    return 0;

}