#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline
int getNumber(const vector<int>&A, int i, int j) {
    int res = 0;
    int mul = 1;
    for (int k = j; k >= i; --k) {
        res += mul * A[k];
        mul *= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // a = b + c/d
    vector<int> A(9);
    iota(A.begin(),A.end(),1);
    int ans = 0;
    // 123456789
    // i       j
    // 0->i (i+1)->(j-1) j->8
    // i+1 <= j-1
    // i+2 <= j
    int a, b, c, d;
    cin >> a;
    do {
        for (int i = 0; i < 7; ++i) {
            for (int j = i+2; j < 9; ++j) {
                // 0->i
                b = getNumber(A, 0, i);
                if (b >= a) {
                    continue;
                }
                // (i+1)->(j-1)
                c = getNumber(A, i+1, j-1);
                // j->8
                d = getNumber(A, j, 8);
                if (c % d == 0 && b + c / d == a) {
                    ++ans;
                }
            }
        }
    } while (next_permutation(A.begin(),A.end()));
    cout << ans << '\n';
    return 0;
}