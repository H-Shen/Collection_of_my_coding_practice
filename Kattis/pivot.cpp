// https://open.kattis.com/problems/pivot
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<ll> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &A.at(i));
    }

    vector<ll> max_from_left(n);
    max_from_left.at(0) = A.front();
    for (int i = 1; i < n; ++i) {
        max_from_left.at(i) = max(max_from_left.at(i - 1), A.at(i));
    }

    vector<ll> min_from_right(n);
    min_from_right.at(n - 1) = A.back();
    for (int i = n - 2; i >= 0; --i) {
        min_from_right.at(i) = min(min_from_right.at(i + 1), A.at(i));
    }

    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            if (A.at(i) == min_from_right.at(0)){
                ++counter;
            }
        } else if (i == n - 1) {
            if (A.at(i) == max_from_left.at(n - 1)) {
                ++counter;
            }
        } else if (A.at(i) > max_from_left.at(i - 1) && A.at(i) < min_from_right.at(i + 1)) {
            ++counter;
        }
    }
    printf("%d\n", counter);

    return 0;
}
