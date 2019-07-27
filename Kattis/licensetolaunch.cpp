// https://open.kattis.com/problems/licensetolaunch
#include<bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(n);
    int minVal = 1000000005;
    int minValIdx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (A[i] < minVal) {
            minValIdx = i;
            minVal = A[i];
        }
    }
    cout << minValIdx << endl;
    return 0;
}
