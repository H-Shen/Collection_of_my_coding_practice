#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, val;
    cin >> n >> m;
    unordered_map<int, int> A;
    int counter = 1;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        if (A.find(val) == A.end()) {
            A[val] = counter;
        }
        ++counter;
    }

    vector<int> B;
    while (m--) {
        cin >> val;
        B.emplace_back(val);
    }
    bool firstItem = true;
    for (auto &i : B) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ' ';
        }
        if (A.find(i) == A.end()) {
            cout << -1;
        } else {
            cout << A[i];
        }
    }
    cout << '\n';
    return 0;
}

