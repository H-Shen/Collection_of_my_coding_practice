#include <cstdio>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return (b > 0) ? gcd(b, a % b) : a;
}

struct Fraction {
    int d;
    int n;
    bool isSimplify = false;

    void Simplify() {
        int Gcd = gcd(n, d);
        n = n / Gcd;
        d = d / Gcd;

        if (Gcd == 1)
            isSimplify = true;
    }
};

bool operator>(const Fraction &a, const Fraction &b) {
    return (a.d * b.n - a.n * b.d > 0);
}

int main() {
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
            A.push_back(i);
        }
    }

    int len = static_cast<int>(A.size());
    for (i = 0; i < len - 1; ++i) {
        printf("%d/%d ", A[i], k);
    }

    printf("%d/%d\n", A[len - 1], k);

    return 0;
}