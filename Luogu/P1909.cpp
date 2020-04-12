#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 3;

int main() {

    vector<pair<int, int> > A(MAXN);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < MAXN; ++i) {
        scanf("%d %d", &A.at(i).first, &A.at(i).second);
    }
    int a = n / A.at(0).first;
    if (n % A.at(0).first != 0) ++a;

    int b = n / A.at(1).first;
    if (n % A.at(1).first != 0) ++b;

    int c = n / A.at(2).first;
    if (n % A.at(2).first != 0) ++c;

    printf("%d\n", min(a * A.at(0).second, min(b * A.at(1).second, c * A.at(2).second)));
    return 0;
}
