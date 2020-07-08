#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

// TPK algorithm
namespace TPK {
    inline double f(const double &t) {
        return sqrt (fabs (t)) + 5.0 * pow (t, 3);
    }
    inline bool is_too_large(int n) {
        return n >= 5;
    }
}

int main(int argc, char *argv[]) {

    int n;
    vector<int> A;
    while (cin >> n) {
        A.emplace_back(n);
    }
    reverse(A.begin(), A.end());
    for (const auto &i : A) {
        if (TPK::is_too_large(i)) {
            cout << "f(" << i << ") = MAGNA NIMIS!";
        } else {
            cout << "f(" << i << ") = ";
            printf("%.2lf", TPK::f(i));
        }
        cout << endl;
    }

    return 0;
}

