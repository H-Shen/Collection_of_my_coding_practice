
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {

    int n, m, i, startPos, endPos;
    ll maxVal = 0, tmp;
    scanf("%d %d", &n, &m);
    ll * A = new ll[n];

    for (i = 0; i < m; i++) {

        scanf("%d %d %lld", &startPos, &endPos, &tmp);
        A[startPos - 1] += tmp;
        A[endPos] -= tmp;
    }

    tmp = 0;
    for (i = 0; i < n; i++) {
        tmp += A[i];
        maxVal = max(tmp, maxVal);
    }

    A = nullptr;
    delete A;

    printf("%lld\n", maxVal);

}
