// https://open.kattis.com/problems/vaccineefficacy

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int sgn(const double &x) {
    static const double EPS = 1e-7;
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

double f(const double &a, const double &b) {
    return (b-a)/b*100.0;
}

int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    vector<string> v(n);
    for (auto &i : v) cin >> i;
    int vaccinated = 0, nonvaccinated = 0;
    int a0 = 0, b0 = 0, c0 = 0;
    int a1 = 0, b1 = 0, c1 = 0;
    for (const auto &i : v) {
        if (i[0] == 'Y') {
            ++vaccinated;
            if (i[1] == 'Y') ++a0;
            if (i[2] == 'Y') ++b0;
            if (i[3] == 'Y') ++c0;
        }
        else {
            ++nonvaccinated;
            if (i[1] == 'Y') ++a1;
            if (i[2] == 'Y') ++b1;
            if (i[3] == 'Y') ++c1;
        }
    }
    double vac_a = a0*1.0/vaccinated;
    double vac_b = b0*1.0/vaccinated;
    double vac_c = c0*1.0/vaccinated;
    double unvac_a = a1*1.0/nonvaccinated;
    double unvac_b = b1*1.0/nonvaccinated;
    double unvac_c = c1*1.0/nonvaccinated;
    if (sgn(vac_a - unvac_a) >= 0) {
        cout << "Not Effective" << '\n';
    } else {
        cout << fixed << setprecision(6) << f(vac_a, unvac_a) << '\n';
    }
    if (sgn(vac_b - unvac_b) >= 0) {
        cout << "Not Effective" << '\n';
    } else {
        cout << fixed << setprecision(6) << f(vac_b, unvac_b) << '\n';
    }
    if (sgn(vac_c - unvac_c) >= 0) {
        cout << "Not Effective" << '\n';
    } else {
        cout << fixed << setprecision(6) << f(vac_c, unvac_c) << '\n';
    }
    return 0;
}
