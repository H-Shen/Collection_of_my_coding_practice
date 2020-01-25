// https://open.kattis.com/problems/taisformula

#include <bits/extc++.h>

using namespace std;

inline static
double area(const pair<double, double> &a, const pair<double, double> &b) {
    return (a.second + b.second) / 2.0 * abs(a.first - b.first);
}

int main() {

    //ios_base::sync_with_stdio(false);
    size_t n;
    cin >> n;
    double first;
    double second;
    vector<pair<double, double> > A(n);
    for (auto &&i : A) {
        cin >> first >> second;
        i = make_pair(first, second);
    }
    double sum = 0.0;
    for (size_t i = 0; i < n - 1; ++i) {
        sum += area(A.at(i), A.at(i + 1));
    }
    sum /= 1000.0;
    printf("%.5lf\n", sum);

    return 0;
}