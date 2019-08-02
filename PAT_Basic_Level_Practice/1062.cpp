#include <bits/stdc++.h>

using namespace std;

struct Fraction {
    int d{};
    int n{};
    bool isSimplify{false};

    void Simplify() {
        int Gcd = __gcd(n, d);
        n /= Gcd;
        d /= Gcd;
        if (Gcd == 1)
            isSimplify = true;
    }
};

bool operator>(const Fraction &a, const Fraction &b) {
    return (a.d * b.n - a.n * b.d > 0);
}

int main() {
#ifdef __GNUC__
    Fraction a, b, tmp;
    int k, i;
    scanf("%d/%d %d/%d %d", &a.d, &a.n, &b.d, &b.n, &k);

    a.Simplify();
    b.Simplify();

    if (a > b) {
        swap(a, b);
    }

    vector<int> A;
    for (i = 1; i < k; ++i) {

        tmp.isSimplify = false;
        tmp.n = k;
        tmp.d = i;
        tmp.Simplify();

        if (!tmp.isSimplify) {
            continue;
        }
        if (tmp > a && b > tmp) {
            A.emplace_back(i);
        }
    }

    int len = static_cast<int>(A.size());
    for (i = 0; i < len - 1; ++i) {
        printf("%d/%d ", A[i], k);
    }

    printf("%d/%d\n", A[len - 1], k);
#endif
    return 0;
}