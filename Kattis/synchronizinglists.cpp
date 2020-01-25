// https://open.kattis.com/problems/synchronizinglists

#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    bool firstCase = true;
    while (true) {
        cin >> n;
        if (n == 0) break;

        if (!firstCase) cout << endl;

        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        vector<int> A_copy(A.begin(), A.end());
        sort(A_copy.begin(), A_copy.end());
        unordered_map<int, int> val2pos;
        for (int i = 0; i < n; ++i) {
            val2pos[A_copy[i]] = i;
        }
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) {
            idx[i] = val2pos[A[i]];
        }

        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        vector<int> B_copy(B.begin(), B.end());
        sort(B_copy.begin(), B_copy.end());
        unordered_map<int, int> B_val2pos;
        for (int i = 0; i < n; ++i) {
            B_val2pos[i] = B_copy[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << B_val2pos[idx[i]] << endl;
        }
        firstCase = false;
    }

    return 0;
}
