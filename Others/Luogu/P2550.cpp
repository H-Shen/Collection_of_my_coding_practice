#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 7;

int main() {

    int n, val;
    scanf("%d", &n);
    unordered_set<int> A;
    for (int i = 0; i < MAXN; ++i) {
        scanf("%d", &val);
        A.insert(val);
    }
    vector<int> stats(MAXN);
    for (int i = 0; i < n; ++i) {
        int counter = 0;
        for (int j = 0; j < MAXN; ++j) {
            scanf("%d", &val);
            if (A.find(val) != A.end()) {
                ++counter;
            }
        }
        for (int j = MAXN; j >= 1; --j) {
            if (counter == j) {
                ++stats.at(MAXN - j);
                break;
            }
        }
    }
    bool first_item = true;
    for (int i = 0; i < MAXN; ++i) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", stats.at(i));
    }
    printf("\n");

    return 0;
}
