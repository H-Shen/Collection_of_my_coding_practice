// https://open.kattis.com/problems/anthonyanddiablo
//
#include <bits/stdc++.h>

using namespace std;
constexpr double EPS = 1e-6;

inline static
int sgn(const double &a) {
    if (a > EPS) {
        return 1;
    }
    if (a > -EPS) {
        return 0;
    }
    return -1;
}

int main() {

    // Isoperimetric inequality: For a given perimeter, a circle has the largest area.
    double A, N;
    cin >> A >> N;
    if (sgn(N * N / (4.0 * M_PI) - A) >= 0) {
        cout << "Diablo is happy!" << endl;
    } else {
        cout << "Need more materials!" << endl;
    }

    return 0;
}
