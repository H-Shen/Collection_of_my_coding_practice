// https://open.kattis.com/problems/bestcompression
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

inline static
ll powerOfTwo(const int &n) {
    ll result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= 2;
    }
    return result;
}

int main() {

    ll N;
    int b;
    cin >> N >> b;
    ll allPossibleSituations = powerOfTwo(b + 1) - 1;
    if (N <= allPossibleSituations) {
        cout << "yes";
    } else {
        cout << "no";
    }
    cout << endl;


    return 0;
}
