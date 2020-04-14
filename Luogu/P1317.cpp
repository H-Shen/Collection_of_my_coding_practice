#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &i : A) scanf("%d", &i);
    vector<int> A_filter;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            A_filter.emplace_back(A.at(i));
            last = A.at(i);
        } else if (A.at(i) != last) {
            A_filter.emplace_back(A.at(i));
            last = A.at(i);
        }
    }
    int counter = 0;
    int length = static_cast<int>(A_filter.size());
    for (int i = 0; i < length - 1; ++i) {
        if (i == 0) {
            continue;
        }
        if (A_filter.at(i) < A_filter.at(i - 1) && A_filter.at(i) < A_filter.at(i + 1)) {
            ++counter;
        }
    }
    printf("%d\n", counter);
    return 0;
}
