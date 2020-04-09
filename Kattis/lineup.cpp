// https://open.kattis.com/problems/lineup
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 20;
char s[MAXN];

int main() {

    int n;
    scanf("%d", &n);
    vector<string> A;
    while (n--) {
        scanf("%s", s);
        A.emplace_back(s);
    }
    vector<string> B(A);
    vector<string> C(A);
    sort(B.begin(), B.end());
    sort(C.begin(), C.end(), greater<>());
    if (A == B) {
        printf("INCREASING\n");
    } else if (A == C) {
        printf("DECREASING\n");
    } else {
        printf("NEITHER\n");
    }

    return 0;
}
