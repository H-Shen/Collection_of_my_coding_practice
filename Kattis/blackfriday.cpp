// https://open.kattis.com/problems/blackfriday
//
#include <bits/extc++.h>

using namespace std;

unordered_map<int, int> A;
vector<int> L;

int main() {

    int n, val;
    scanf("%d", &n);
    L.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        ++A[val];
        L.at(i) = val;
    }

    int maxVal = -1;
    for (const auto &it : A) {
        if (it.second == 1) {
            maxVal = max(maxVal, it.first);
        }
    }
    if (maxVal == -1) {
        printf("none\n");
    } else {
        printf("%d\n", static_cast<int>(find(L.begin(), L.end(), maxVal) - L.begin()) + 1);
    }

    return 0;
}
