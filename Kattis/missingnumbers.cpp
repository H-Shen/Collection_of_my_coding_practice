// https://open.kattis.com/problems/missingnumbers
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n, val;
    cin >> n;
    unordered_set<int> A;
    int maxVal = -1;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        A.insert(val);
        maxVal = max(maxVal, val);
    }
    bool hasAns = false;
    for (int i = 1; i <= maxVal; ++i) {
        if (A.find(i) == A.end()) {
            hasAns = true;
            cout << i << '\n';
        }
    }
    if (!hasAns) {
        cout << "good job\n";
    }

    return 0;
}
