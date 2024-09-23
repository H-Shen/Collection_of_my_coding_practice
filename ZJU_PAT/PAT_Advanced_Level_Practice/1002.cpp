#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-6;

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a < eps) return 0;
    return 1;
}

int main() {

    unordered_map<int, double> A, B;
    int maxTime = -1;
    vector<pair<int, double> > res;

    int n;
    int i;
    int time;
    double coeff;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d %lf", &time, &coeff);
        maxTime = max(maxTime, time);
        A[time] = coeff;
    }

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d %lf", &time, &coeff);
        maxTime = max(maxTime, time);
        B[time] = coeff;
    }

    for (i = maxTime; i >= 0; --i) {

        pair<int, double> item;
        item.first = i;

        if (A.find(i) == A.end()) {
            A[i] = 0.0;
        }
        if (B.find(i) == B.end()) {
            B[i] = 0.0;
        }

        item.second = B[item.first] + A[item.first];
        if (sgn(item.second) == 0) {
            continue;
        }
        res.push_back(item);
    }

    if (res.empty()) {
        printf("0\n");
    } else {

        printf("%d ", static_cast<int>(res.size()));

        for (i = 0; i < static_cast<int>(res.size()) - 1; ++i) {
            printf("%d %.1lf ", res[i].first, res[i].second);
        }
        printf("%d %.1lf\n", res[i].first, res[i].second);
    }
    return 0;
}
