// https://open.kattis.com/problems/overdraft

#include <bits/stdc++.h>

using namespace std;

int n;
int minVal;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int val;
    minVal = numeric_limits<int>::max();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        sum += val;
        minVal = min(minVal, sum);
    }
    if (minVal < 0) {
        minVal = -minVal;
    }
    else {
        minVal = 0;
    }
    cout << minVal << '\n';
    return 0;
}
