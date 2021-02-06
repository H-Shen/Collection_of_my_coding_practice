#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &A.at(i).first, &A.at(i).second);
    }
    int maxDist = -1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            maxDist = max(maxDist, (A[i].first-A[j].first)*(A[i].first-A[j].first)+(A[i].second-A[j].second)*(A[i].second-A[j].second));
        }
    }
    printf("%.5lf\n", sqrt(maxDist * 1.0));

    return 0;
}
