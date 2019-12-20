// https://ac.nowcoder.com/acm/problem/15188

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct item {
    ll exp;
    ll coeff;
};

struct item operator*(const item &a, const item &b) {
    item res{};
    res.exp = a.exp + b.exp;
    res.coeff = a.coeff * b.coeff;
    return res;
}

bool cmp(const item &a, const item &b) {
    return (a.exp < b.exp);
}

vector<item> mulArr(const vector<item> &A, const vector<item> &B) {
    vector<item> res;

    if (A.empty() || B.empty()) {
        return res;
    }

    int lenA = static_cast<int>(A.size());
    int lenB = static_cast<int>(B.size());

    int i, j;
    item tmp{};
    unordered_map<ll, item> save;

    for (i = 0; i < lenA; ++i) {
        for (j = 0; j < lenB; ++j) {
            tmp = A[i] * B[j];
            save[tmp.exp].coeff += tmp.coeff;
            save[tmp.exp].exp = tmp.exp;
        }
    }

    for (const auto &it : save) {
        res.push_back(it.second);
    }

    return res;
}

int main() {
    int lenA, lenB, i;
    item tmp{};

    scanf("%d %d", &lenA, &lenB);
    ++lenA;
    ++lenB;

    vector<item> A(static_cast<unsigned long>(lenA));
    for (i = 0; i < lenA; ++i) {
        scanf("%lld", &tmp.coeff);
        tmp.exp = static_cast<ll>(i);
        A[i] = tmp;
    }

    vector<item> B(lenB);
    for (i = 0; i < lenB; ++i) {
        scanf("%lld", &tmp.coeff);
        tmp.exp = static_cast<ll>(i);
        B[i] = tmp;
    }

    //Mul
    vector<item> C = mulArr(A, B);
    if (C.empty()) {
        cout << "Error" << endl;
    } else {
        sort(C.begin(), C.end(), cmp);
        printf("%lld", C[0].coeff);
        for (i = 1; i < static_cast<int>(C.size()); ++i) {
            printf(" %lld", C[i].coeff);
        }
    }
    printf("\n");

    return 0;
}