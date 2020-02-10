#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    ll m;
    scanf("%d %lld", &n, &m);
    vector<ll> A(n);
    int position_of_median = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &A.at(i));
        if (A.at(i) == m) {
            position_of_median = i;
        }
    }
    if (position_of_median == -1) {
        printf("0\n");
        return 0;
    }
    // Scan left
    ll larger = 0;
    ll smaller = 0;
    unordered_map<ll, ll> larger_minus_smaller;
    for (int i = position_of_median; i >= 0; --i) {
        if (i == position_of_median) {
            continue;
        }
        if (A.at(i) > m) {
            ++larger;
        } else {
            ++smaller;
        }
        ++larger_minus_smaller[larger - smaller];
    }
    // Scan right
    larger = 0;
    smaller = 0;
    unordered_map<ll, ll> smaller_minus_larger;
    for (int i = position_of_median; i < n ; ++i) {
        if (i == position_of_median) {
            continue;
        }
        if (A.at(i) > m) {
            ++larger;
        } else {
            ++smaller;
        }
        ++smaller_minus_larger[smaller - larger];
    }
    // Stats
    ll counter = 0;
    // Add self
    ++counter;

    // Left side of the median only
    if (larger_minus_smaller.find(0) != larger_minus_smaller.end()) {
        counter += larger_minus_smaller[0];
    }
    // Right side of the median only
    if (smaller_minus_larger.find(0) != smaller_minus_larger.end()) {
        counter += smaller_minus_larger[0];
    }
    // Left side matches right side
    for (const auto &i : larger_minus_smaller) {
        if (smaller_minus_larger.find(i.first) != smaller_minus_larger.end()) {
            counter += i.second * smaller_minus_larger[i.first];
        }
    }
    printf("%lld\n", counter);
    return 0;
}