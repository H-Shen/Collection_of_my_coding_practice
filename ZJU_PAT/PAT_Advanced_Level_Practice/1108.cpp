#include <bits/stdc++.h>

using namespace std;
const double EPS = 1e-6;

inline int sgn(const double &a) {
    if (a < -EPS) {
        return -1;
    }
    if (a < EPS) {
        return 0;
    }
    return 1;
}

bool isLegal(const string &s) {
    int decimalCnt = 0;
    bool haveDigit = false;
    int len = s.size();
    int i;
    for (i = 0; i < len; ++i) {
        if (i == 0 && s[i] == '-') {
            continue;
        }
        if (i != 0 && s[i] == '.') {
            ++decimalCnt;
            continue;
        }
        if (!isdigit(s[i])) {
            return false;
        } else {
            haveDigit = true;
        }
    }
    if (decimalCnt > 1) {
        return false;
    }
    if (!haveDigit) {
        return false;
    }
    if (decimalCnt == 1) {
        string tmp;
        if (s[s.size() - 1] != '.') {
            tmp = s.substr(s.find('.') + 1);
        }
        if (tmp.size() > 2) {
            return false;
        }
        double tmpDouble = stod(s);
        if (sgn(tmpDouble - 1000) == 1 || sgn(tmpDouble + 1000) == -1) {
            return false;
        }
    } else {
        if (s.size() > 5) {
            return false;
        }
        int tmp = stoi(s);
        if (tmp < -1000 || tmp > 1000) {
            return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    int n, i;
    cin >> n;
    vector<double> A;
    vector<string> illegal;
    string input;

    for (i = 0; i < n; ++i) {
        cin >> input;
        if (isLegal(input)) {
            A.push_back(stod(input));
        } else {
            illegal.push_back(input);
        }
    }

    for (const auto &p : illegal) {
        cout << "ERROR: " << p << " is not a legal number" << endl;
    }

    if (A.empty()) {
        cout << "The average of 0 numbers is Undefined" << endl;
    } else if (A.size() == 1) {
        cout << "The average of 1 number is ";
        printf("%.2lf\n", A[0]);
    } else {
        cout << "The average of " << A.size() << " numbers is ";
        printf("%.2lf\n", accumulate(A.begin(), A.end(), static_cast<double>(0)) / static_cast<double>(A.size()));
    }

    return 0;
}
