// https://open.kattis.com/problems/stirlingsapproximation
//
#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 100001;
vector<double> sumList(maxn);

inline static
void sum() {
    double s = 0.0;
    for (int i = 1; i <= 100000; ++i) {
        s += log(static_cast<double>(i));
        sumList.at(i) = s;
    }
}

inline static
double remain(int n) {
    return 0.5*log(2.0*M_PI*n)+n*(log(n) - 1);
}

int main() {

    int n;
    sum();
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        double p = sumList.at(n) - remain(n);
        printf("%.9lf\n", pow(M_E, p));
    }
    
    return 0;
}
