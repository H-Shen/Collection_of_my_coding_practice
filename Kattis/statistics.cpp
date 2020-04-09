// https://open.kattis.com/problems/statistics
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int kase = 1;
    int n;
    while (~scanf("%d", &n)) {
        vector<int> A(n);
        for (auto &i : A) {
            scanf("%d", &i);
        }
        int max_val = *max_element(A.begin(), A.end());
        int min_val = *min_element(A.begin(), A.end());
        printf("Case %d: %d %d %d\n", kase, min_val, max_val, max_val - min_val);
        ++kase;
    }

    return 0;
}
