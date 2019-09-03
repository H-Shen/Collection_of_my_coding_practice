// https://open.kattis.com/problems/prsteni
//
#include <bits/stdc++.h>

using namespace std;

struct Fraction {
    int a;
    int b;
    void printLn() {
        if (a % b == 0) {
            a /= b;
            b = 1;
        } else {
            int tempVal = __gcd(a, b);
            a /= tempVal;
            b /= tempVal;
        }
        printf("%d/%d\n", a, b);
    }
};

int main() {

    int n;
    scanf("%d", &n);
    int firstItem;
    scanf("%d", &firstItem);
    vector<Fraction> A(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        A[i].a = firstItem;
        scanf("%d", &A[i].b);
    }
    for (auto &i : A) {
        i.printLn();
    }

    return 0;
}
