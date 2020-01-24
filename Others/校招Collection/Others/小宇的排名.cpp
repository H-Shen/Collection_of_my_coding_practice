// https://ac.nowcoder.com/acm/problem/24662

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    vector<int> A;
    int val;
    while (~scanf("%d", &val)) {
        A.emplace_back(val);
    }
    int score = A.back();
    sort(A.begin(), A.end(), greater<>());
    int n = static_cast<int>(A.size());
    for (int i = 0; i < n; ++i) {
        if (A.at(i) == score) {
            printf("%d\n", i + 1);
            break;
        }
    }

    return 0;
}
