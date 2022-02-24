// https://open.kattis.com/problems/simone

#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

constexpr int MAXN = 1e3+5;
int freq[MAXN];

int main() {
    int n,k,val;
    cin >> n >> k;
    vector<int> A;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        ++freq[val];
    }
    int minVal = numeric_limits<int>::max();
    for (int i = 1; i <= k; ++i) {
        minVal = min(minVal, freq[i]);
    }
    for (int i = 1; i <= k; ++i) {
        if (freq[i] == minVal) {
            A.emplace_back(i);
        }
    }
    cout << A.size() << '\n';
    bool first = true;
    for (auto&i : A) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << i;
    }
    cout << '\n';
    return 0;
}
