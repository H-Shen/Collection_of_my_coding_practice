#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {

    int n, k, i;
    scanf("%d %d", &n, &k);
    vector <ll> A(n);
    for (i = 0; i < n; ++i) {
        scanf("%lld", &A[i]);
    }
    sort(A.begin(), A.end());

    ll minVal = A[0], maxVal = A[k - 1];
    ll unfairness = maxVal - minVal;
    ll tmp = unfairness;
    int minValPos = 0, maxValPos = k - 1;

    while (maxValPos != n - 1) {
        ++minValPos;
        ++maxValPos;
        tmp = A[maxValPos] - A[minValPos];
        unfairness = min(unfairness, tmp);
    }

    printf("%lld\n", unfairness);

    return 0;
}
