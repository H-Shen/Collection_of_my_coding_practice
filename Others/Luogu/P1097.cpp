#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

unordered_map<int, int> A;

int main() {

    int n;
    int val;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        ++A[val];
    }
    vector<pair<int, int> > output(A.begin(), A.end());
    sort(output.begin(), output.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return (lhs.first < rhs.first);
    });
    for (const auto &[key, value] : output) {
        printf("%d %d\n", key, value);
    }

    return 0;
}