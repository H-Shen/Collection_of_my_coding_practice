// https://ac.nowcoder.com/acm/contest/543/A

#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 1000;
unordered_set<int> save;

int main() {

    // pre
    for (int i = 1; i * i <= maxn; ++i) {
        save.insert(i * i);
    }

    int n, val;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &&i : A) {
        scanf("%d", &val);
        if (save.find(val) == save.end()) {
            i = val;
        }
    }
    printf("%d\n", *max_element(A.begin(), A.end()));

    return 0;
}