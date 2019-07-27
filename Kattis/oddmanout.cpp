// https://open.kattis.com/problems/oddmanout
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, val;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        unordered_map<int, int> A;
        while (m--) {
            cin >> val;
            ++A[val];
        }
        for (auto &&k : A) {
            if (k.second == 1) {
                cout << "Case #" << i << ": " << k.first << endl;
                break;
            }
        }
    }
    return 0;
}
