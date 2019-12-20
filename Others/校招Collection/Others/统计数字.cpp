// https://ac.nowcoder.com/acm/problem/16643

#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> A;
vector<pair<int, int> > output;

int main() {

    int n, val;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        ++A[val];
    }
    output.resize(A.size());
    auto output_iter = output.begin();
    for (const auto &it : A) {
        *output_iter = make_pair(it.first, it.second);
        ++output_iter;
    }
    sort(output.begin(), output.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return (lhs.first < rhs.first);
    });
    // output
    for (const auto &i : output) {
        printf("%d %d\n", i.first, i.second);
    }

    return 0;
}