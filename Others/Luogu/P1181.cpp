#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

// greedy
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    int groups = 0;
    int current_sum = 0;
    for (const auto &i : A) {
        if (current_sum + i <= m) {
            current_sum += i;
        } else {
            ++groups;
            current_sum = i;
        }
    }
    if (current_sum > 0) {
        ++groups;
    }
    printf("%d\n", groups);
    return 0;
}