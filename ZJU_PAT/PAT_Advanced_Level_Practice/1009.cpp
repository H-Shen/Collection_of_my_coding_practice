#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-6;

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a < eps) return 0;
    return 1;
}

struct item {
    int exp;
    double coeff;
};

struct item operator*(const item &a, const item &b) {
    item res;
    res.exp = a.exp + b.exp;
    res.coeff = a.coeff * b.coeff;
    return res;
}

bool cmp(const item &a, const item &b) {
    return (a.exp > b.exp);
}

vector<item> mulArr(const vector<item> &A, const vector<item> &B) {
    vector<item> res;

    if (A.empty() || B.empty()) {
        return res;
    }

    int lenA = static_cast<int>(A.size());
    int lenB = static_cast<int>(B.size());

    int i, j;
    item tmp;
    unordered_map<int, item> save;

    for (i = 0; i < lenA; ++i) {
        for (j = 0; j < lenB; ++j) {
            tmp = A[i] * B[j];
            save[tmp.exp].coeff += tmp.coeff;
            save[tmp.exp].exp = tmp.exp;
        }
    }

    for (auto it = save.cbegin(); it != save.cend(); ++it) {
        if (sgn(it->second.coeff) != 0) {
            res.push_back(it->second);
        }
    }

    return res;
}

int main() {
    int N, i;
    item tmp;

    scanf("%d", &N);
    vector<item> A(N);
    for (i = 0; i < N; ++i) {
        scanf("%d %lf", &tmp.exp, &tmp.coeff);
        A[i] = tmp;
    }

    scanf("%d", &N);
    vector<item> B(N);
    for (i = 0; i < N; ++i) {
        scanf("%d %lf", &tmp.exp, &tmp.coeff);
        B[i] = tmp;
    }

    vector<item> C = mulArr(A, B);

    if (C.empty()) {
        printf("0");
    } else {
        sort(C.begin(), C.end(), cmp);
        printf("%d", static_cast<int>(C.size()));
        for (i = 0; i < static_cast<int>(C.size()); ++i) {
            printf(" %d %.1lf", C[i].exp, C[i].coeff);
        }
    }
    return 0;
}
