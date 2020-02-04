// https://open.kattis.com/problems/awkwardparty
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, val;
    scanf("%d", &n);
    vector<int> A(n);
    unordered_set<int> unique_check;
    unordered_map<int, vector<int> > seats_stats;
    int min_val = numeric_limits<int>::max();
    int min_val_scope;
    int length_scope;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        seats_stats[val].emplace_back(i);
        unique_check.insert(val);
    }
    if (static_cast<int>(unique_check.size()) == n) {
        printf("%d\n", n);
    } else {
        for (auto &i : seats_stats) {
            if (i.second.size() > 1) {
                min_val_scope = numeric_limits<int>::max();
                length_scope = static_cast<int>(i.second.size());
                sort(i.second.begin(), i.second.end());
                for (int j = 0; j < length_scope - 1; ++j) {
                    min_val_scope = min(min_val_scope, i.second.at(j + 1) - i.second.at(j));
                }
                min_val = min(min_val, min_val_scope);
            }
        }
        printf("%d\n", min_val);
    }

    return 0;
}
