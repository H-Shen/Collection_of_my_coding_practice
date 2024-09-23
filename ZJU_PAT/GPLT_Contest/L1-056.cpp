#include <bits/stdc++.h>

using namespace std;

double eps = 1e-6;

int cmpDouble(const double &diff) {
    if (diff < -eps) {
        return -1;
    }
    if (diff < eps) {
        return 0;
    }
    return 1;
}

int main() {
    int n, i;
    cin >> n;
    string a;
    int b;
    double sum = 0.0;

    unordered_map<string, double> A;

    for (i = 0; i < n; ++i) {
        cin >> a >> b;
        A[a] = b;
        sum += b;
    }

    double avg = (sum / static_cast<double>(n)) / 2.0;
    double minVal = 150.0;
    string winner;

    for (auto it = A.begin(); it != A.end(); ++it) {
        it->second = abs(it->second - avg);
        if (cmpDouble(it->second - minVal) == -1) {
            minVal = it->second;
            winner = it->first;
        }
    }

    cout << static_cast<int>(avg) << ' ' << winner << endl;

    return 0;

}