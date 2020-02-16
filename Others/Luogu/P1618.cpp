#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    vector<int> A(9);
    iota(A.begin(), A.end(), 1);
    int a, b, c, a_, b_, c_, m, m_, a_copy, b_copy, c_copy;
    bool haveAns = false;
    scanf("%d %d %d", &a_, &b_, &c_);

    if (a_ == 0 || b_ == 0 || c_ == 0) {
        printf("No!!!\n");
        return 0;
    }
    if (a_ < 0 && b_ < 0 && c_ > 0) {
        printf("No!!!\n");
        return 0;
    }
    if (a_ < 0 && b_ < 0 && c_ < 0) {
        a_ = -a_;
        b_ = -b_;
        c_ = -c_;
    }


    do {
        a = 100 * A[0] + 10 * A[1] + A[2];
        b = 100 * A[3] + 10 * A[4] + A[5];
        c = 100 * A[6] + 10 * A[7] + A[8];

        a_copy = a;
        b_copy = b;
        c_copy = c;

        m = __gcd(__gcd(a, b), c);
        a /= m; b /= m; c /= m;

        m_ = __gcd(__gcd(a_, b_), c_);
        a_ /= m_; b_ /= m_; c_ /= m_;

        if (a == a_ && b == b_ && c == c_) {
            printf("%d %d %d\n", a_copy, b_copy, c_copy);
            haveAns = true;
        }
    } while (next_permutation(A.begin(), A.end()));
    if (!haveAns) {
        printf("No!!!\n");
    }
    return 0;
}