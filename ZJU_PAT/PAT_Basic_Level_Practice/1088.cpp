#include <bits/stdc++.h>

using namespace std;

const int MINN = 10, MAXN = 99;
const double EPS = 1e-10;

inline
int sgn(double a) {
    if (a < -EPS)
        return -1;
    else if (a < EPS)
        return 0;
    return 1;
}

inline
int convert(int n) {
    return (n % 10) * 10 + n / 10;
}

inline
string cmpInt(int a, int b) {
    if (a == b) {
        return "Ping";
    } else if (a > b) {
        return "Gai";
    }
    return "Cong";
}

inline
string cmpDouble(double a, double b) {
    if (sgn(a - b) == 0) {
        return "Ping";
    } else if (sgn(a - b) < 0) {
        return "Cong";
    }
    return "Gai";
}

int main() {
    ios_base::sync_with_stdio(false);
    int jia, yi, m, x, y;
    double bing;

    cin >> m >> x >> y;
    int jia_tmp, yi_tmp;
    jia = -1;
    for (jia_tmp = MINN; jia_tmp <= MAXN; ++jia_tmp) {
        yi_tmp = convert(jia_tmp);
        if (y * abs(jia_tmp - yi_tmp) == x * yi_tmp) {
            if (jia_tmp > jia) {
                jia = jia_tmp;
            }
        }
    }

    if (jia == -1) {
        cout << "No Solution";
    } else {
        yi = convert(jia);
        bing = yi * 1.0 / y;
        cout << jia << ' ' << cmpInt(m, jia) << ' ' << cmpInt(m, yi) << ' '
             << cmpDouble(static_cast<double>(m), bing);
    }
    cout << endl;


    return 0;
}