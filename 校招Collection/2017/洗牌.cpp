// https://www.nowcoder.com/practice/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    int T, n, k, i, j;
    bool change;

    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<int> A(2 * n);
        vector<int> B(2 * n);
        for (i = 0; i < 2 * n; i++) {
            cin >> A[i];
        }
        change = false;
        while (k--) {
            B = A;
            for (j = 0; j < 2 * n; j++) {
                if (!change) {
                    B[j] = A[2 * n - 1 - j / 2];
                    change = true;
                } else {
                    B[j] = A[n - 1 - j / 2];
                    change = false;
                }
            }
            A = B;
            reverse(A.begin(), A.end());
        }
        for (i = 0; i < 2 * n - 1; i++) {
            cout << A[i] << ' ';
        }
        cout << A[2 * n - 1] << endl;
    }
    return 0;
}