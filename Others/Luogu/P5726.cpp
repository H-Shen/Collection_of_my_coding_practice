#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    int s = 0;
    for (auto &i : A) {
        scanf("%d", &i);
        s += i;
    }
    s -= *max_element(A.begin(), A.end());
    s -= *min_element(A.begin(), A.end());
    printf("%.2lf\n", s *1.0 / (n - 2));
    return 0;
}