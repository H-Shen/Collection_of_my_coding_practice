// https://open.kattis.com/problems/polymul1
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct item
{
    ll exp;
    ll coeff;
};

struct item operator * (const item &a, const item &b)
{
    item res{};
    res.exp = a.exp + b.exp;
    res.coeff = a.coeff * b.coeff;
    return res;
}

bool cmp (const item &a, const item &b)
{
    return (a.exp < b.exp);
}

vector <item> mulArr(const vector <item> &A, const vector <item> &B)
{
    vector <item> res;

    if (A.empty() || B.empty()) {
        return res;
    }

    int lenA = static_cast<int>(A.size());
    int lenB = static_cast<int>(B.size());
    int i, j;

    item tmp{};
    unordered_map <int, item> save;

    for (i = 0; i < lenA; ++i) {
        for (j = 0; j < lenB; ++j) {
            tmp = A[i] * B[j];
            save[tmp.exp].coeff += tmp.coeff;
            save[tmp.exp].exp = tmp.exp;
        }
    }
    res.resize(save.size());
    auto iter = res.begin();
    for (const auto & it : save) {
        *iter = it.second;
        ++iter;
    }

    return res;
}

int main()
{
    int T, N, i;
    item tmp{};
    scanf("%d", &T);
    while (T--) {

        scanf("%d", &N);
        ++N;
        vector<item> A(N);
        for (i = 0; i < N; ++i) {
            scanf("%lld", &tmp.coeff);
            tmp.exp = static_cast<ll>(i);
            A[i] = tmp;
        }

        scanf("%d", &N);
        ++N;
        vector<item> B(N);
        for (i = 0; i < N; ++i) {
            scanf("%lld", &tmp.coeff);
            tmp.exp = static_cast<ll>(i);
            B[i] = tmp;
        }

        vector<item> C = mulArr(A, B);
        bool firstItem = true;
        if (C.empty()) {
            printf("0\n0\n");
        } else {
            sort(C.begin(), C.end(), cmp);
            printf("%d\n", (int) C.size() - 1);
            for (i = 0; i < (int) C.size(); ++i) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    printf(" ");
                }
                printf("%lld", C[i].coeff);
            }
        }
        printf("\n");
    }
    return 0;
}
