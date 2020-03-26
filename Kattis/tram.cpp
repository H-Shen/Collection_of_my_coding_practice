// https://open.kattis.com/problems/tram
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        A.at(i) = y - x;
    }
    printf("%.6lf\n", accumulate(A.begin(), A.end(), 0) * 1.0 / n);


    return 0;
}
