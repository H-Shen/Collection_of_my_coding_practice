// https://open.kattis.com/problems/hothike
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A) {
        cin >> i;
    }
    int minVal = 1000;
    int d = 0;
    int temp;
    for (int i = 0; i < n - 2; ++i) {
        temp = max(A.at(i), A.at(i + 2));
        if (temp < minVal) {
            minVal = temp;
            d = i + 1;
        }
    }
    cout << d << ' ' << minVal << endl;

    return 0;
}
