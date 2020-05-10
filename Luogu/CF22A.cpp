#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n, val;
    scanf("%d", &n);
    set<int> A;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        A.insert(val);
    }
    if (A.size() < 2) {
        printf("NO\n");
    } else {
        auto iter = A.cbegin();
        ++iter;
        printf("%d\n", *iter);
    }


    return 0;
}