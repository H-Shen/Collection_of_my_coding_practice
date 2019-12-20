#include <bits/stdc++.h>

using namespace std;

struct item {
    int coeff;
    int degree;
};

int main() {
    int a, b;
    item tmp;
    vector<item> A;
    while (~scanf("%d %d", &a, &b)) {
        tmp.coeff = a * b;
        if (b != 0)
            tmp.degree = b - 1;
        else {
            tmp.degree = 0;
        }
        if (tmp.degree == 0 && tmp.coeff == 0) {
            continue;
        }
        A.push_back(tmp);
    }
    if (A.empty()) {
        printf("0 0\n");
        return 0;
    }
    size_t i;
    for (i = 0; i < A.size() - 1; ++i) {
        printf("%d %d ", A[i].coeff, A[i].degree);
    }
    printf("%d %d\n", A[A.size() - 1].coeff, A[A.size() - 1].degree);
    return 0;
}
