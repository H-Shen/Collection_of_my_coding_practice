#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 1000;

unordered_set<int> A, B, C, D;

int main() {

    for (int i = 0; i <= MAXN; ++i) {
        if (i % 2 == 0 && (i > 4 && i <= 12) ) {
            A.insert(i);
        }
        if (i % 2 == 0 || (i > 4 && i <= 12) ) {
            B.insert(i);
        }
        if ( ((i % 2 != 0) && (i > 4 && i <= 12)) || ((i % 2 == 0) && (i <= 4 || i > 12)) ) {
            C.insert(i);
        }
        if ( (i % 2 != 0) && (i <= 4 || i > 12) ) {
            D.insert(i);
        }
    }
    int n;
    scanf("%d", &n);
    bool bool_A = (A.find(n) == A.end()) ? false : true;
    bool bool_B = (B.find(n) == B.end()) ? false : true;
    bool bool_C = (C.find(n) == C.end()) ? false : true;
    bool bool_D = (D.find(n) == D.end()) ? false : true;
    printf("%d %d %d %d\n", (int)bool_A, (int)bool_B, (int)bool_C, (int)bool_D);

    return 0;
}