// https://open.kattis.com/problems/polymul2
//
#include <bits/extc++.h>

using namespace std;

struct Complex {
    double x, y;

    Complex(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

    Complex operator-(const Complex &b) const {
        return Complex(x - b.x, y - b.y);
    }

    Complex operator+(const Complex &b) const {
        return Complex(x + b.x, y + b.y);
    }

    Complex operator*(const Complex &b) const {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

const int MAXN = 400000;
vector<Complex> A(MAXN);
vector<Complex> B(MAXN);
vector<int> rev(MAXN);

void fft(vector<Complex> &a, int n, int t) {
    for (int i = 0; i < n; i++) {
        if (i < rev.at(i)) {
            swap(a.at(i), a.at(rev.at(i)));
        }
    }
    for (int j = 1; j < n; j <<= 1) {
        Complex wn(cos(2 * M_PI / (j << 1)), t * sin(2 * M_PI / (j << 1)));
        for (int i = 0; i < n; i += (j << 1)) {
            Complex w(1, 0), t0, t1;
            for (int k = 0; k < j; k++, w = w * wn) {
                t0 = a.at(i + k);
                t1 = w * a.at(i + j + k);
                a.at(i + k) = t0 + t1;
                a.at(i + j + k) = t0 - t1;
            }
        }
    }
}


int main() {

    int temp;
    scanf("%d", &temp);

    int n;
    scanf("%d", &n);
    ++n;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &A.at(i).x);
    }
    int m;
    scanf("%d", &m);
    ++m;
    for (int i = 0; i < m; ++i) {
        scanf("%lf", &B.at(i).x);
    }
    int nn = 1;
    int len = 0;
    while (nn <= n + m - 2) {
        nn <<= 1;
        ++len;
    }
    rev.at(0) = 0;
    for (int i = 1; i < nn; ++i) {
        rev.at(i) = (rev.at(i >> 1) >> 1) | ((i & 1) << (len - 1));
    }
    fft(A, nn, 1);
    fft(B, nn, 1);
    for (int i = 0; i <= nn; ++i) {
        A.at(i) = A.at(i) * B.at(i);
    }
    fft(A, nn, -1);

    // output
    bool firstItem = true;
    printf("%d\n", n + m - 2);
    for (int i = 0; i <= n + m - 2; i++) {
        if (firstItem) {
            firstItem = false;
        } else {
            printf(" ");
        }
        printf("%lld", static_cast<long long>(round(A.at(i).x / nn)));
    }
    printf("\n");

    return 0;
}
