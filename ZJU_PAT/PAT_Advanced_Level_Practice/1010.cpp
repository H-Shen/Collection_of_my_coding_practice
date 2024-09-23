#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;
const int MAXN = 3;

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a < eps) return 0;
    return 1;
}

bool cmp(const double &a, const double &b) {
    return (sgn(a - b) == -1);
}

double mul(const double &a, const double &b) {
    return a * b;
}

int main() {
    int i, j;

    vector<vector<double> > A(MAXN);
    for (i = 0; i < MAXN; ++i) {
        A[i].resize(MAXN);
    }

    for (i = 0; i < MAXN; ++i) {
        for (j = 0; j < MAXN; ++j) {
            scanf("%lf", &A[i][j]);
        }
    }

    vector<double> maxValList(MAXN);
    vector<char> maxValRes(MAXN);
    double maxVal;
    int idx = 0;
    for (i = 0; i < MAXN; ++i) {
        maxVal = *max_element(A[i].begin(), A[i].end(), cmp);
        maxValList[i] = maxVal;
        for (j = 0; j < MAXN; ++j) {
            if (sgn(maxVal - A[i][j]) == 0) {
                idx = j;
                break;
            }
        }
        switch (idx) {
            case 0 :
                maxValRes[i] = 'W';
                break;
            case 1 :
                maxValRes[i] = 'T';
                break;
            case 2 :
                maxValRes[i] = 'L';
                break;
            default:
                break;
        }
    }

    for (i = 0; i < MAXN; ++i) {
        printf("%c ", maxValRes[i]);
    }
    double res = (accumulate(maxValList.begin(), maxValList.end(), (double) 1, mul) * 0.65 - 1.0) * 2.0;
    printf("%.2lf\n", res);
    return 0;
}