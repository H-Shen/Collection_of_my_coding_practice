#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;
const double minBound = -1000.0, maxBound = 1000.0;

int sgn(double a) {
    if (a < -EPS) {
        return -1;
    }
    if (a < EPS) {  //a==0
        return 0;
    }
    return 1;       //a>0
}

bool check(string s, double &test) {

    int i;
    int len = static_cast<int>(s.size());
    int cntDecimal = 0;
    int cntNegativeSign = 0;
    int cntPositiveSign = 0;

    for (i = 0; i < len; ++i) {
        if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '.' || s[i] == '+')) {
            return false;
        }
        if (s[i] == '.') {
            ++cntDecimal;
        }
        if (s[i] == '-') {
            ++cntNegativeSign;
            if (i != 0) {
                return false;
            }
        }
        if (s[i] == '+') {
            ++cntPositiveSign;
            if (i != 0) {
                return false;
            }
        }
    }
    if (cntDecimal > 1) {
        return false;
    }

    try {
        test = stod(s);
    } catch (...) {
        return false;
    }

    bool inDecimal = false;
    int cnt = 0;
    for (i = 0; i < len; ++i) {
        if (s[i] == '.') {
            inDecimal = true;
        } else if (inDecimal) {
            ++cnt;
        }
    }
    if (cnt > 2) {
        return false;
    }

    if (!(sgn(test - minBound) >= 0 && sgn(maxBound - test) >= 0)) {
        return false;
    }

    return true;
}

int main() {
    int n;
    string s;
    double sum = 0.0, test = 0.0;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (check(s, test)) {
            sum += test;
            ++cnt;
        } else {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        }
    }
    if (cnt == 0) {
        cout << "The average of " << cnt << " numbers is Undefined" << endl;
    } else if (cnt == 1) {
        cout << "The average of 1 number is ";
        printf("%.2lf\n", sum);
    } else {
        cout << "The average of " << cnt << " numbers is ";
        printf("%.2lf\n", sum / cnt);
    }
    return 0;
}