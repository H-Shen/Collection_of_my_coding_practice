#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
unordered_map<int, int> A;

int main() {

    int n, m, val;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        A[val] = i;
    }
    vector<pair<int, int> > output;
    while (m--) {
        scanf("%d", &val);
        if (A.find(val) != A.end()) {
            output.emplace_back(make_pair(val, A[val]));
        }
    }
    sort(output.begin(), output.end(), [](const pair<int, int> &l, const pair<int, int> &r) {
        return l.second < r.second;
    });
    bool first_item = true;
    for (const auto &[k, v] : output) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", k);
    }
    printf("\n");
    return 0;
}