// https://open.kattis.com/problems/cookingwater
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    int min_val = numeric_limits<int>::max();
    int max_val = numeric_limits<int>::min();
    scanf("%d", &n);
    vector<pair<int, int> > A(n);
    for (auto &i : A) {
        scanf("%d %d", &i.first, &i.second);
        min_val = min(min_val, i.first);
        max_val = max(max_val, i.second);
    }
    bool have_ans;
    for (int i = min_val; i <= max_val; ++i) {
        have_ans = true;
        for (const auto &item : A) {
            if (!(i >= item.first && i <= item.second)) {
                have_ans = false;
                break;
            }
        }
        if (have_ans) {
            printf("gunilla has a point\n");
            return 0;
        }
    }
    printf("edward is right\n");
    return 0;
}
