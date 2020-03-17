// https://open.kattis.com/problems/neighborhoodwatch
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

ll comb(ll n) {
    return n*(n-1)/2;
}

ll solve(const vector<bool> &A) {
    vector<pair<int, int> > segments;
    int length = static_cast<int>(A.size());
    bool in_segment = false;
    int start_pos{};
    int end_pos{};
    for (int i = 0; i < length; ++i) {
        if (!A.at(i)) {
            if (in_segment) {
                ++end_pos;
            } else {
                in_segment = true;
                start_pos = i;
                end_pos = start_pos;
            }
        } else {
            if (in_segment) {
                in_segment = false;
                segments.emplace_back(start_pos, end_pos);
            }
        }
    }
    if (in_segment) {
        segments.emplace_back(start_pos, end_pos);
    }

    ll counter = 0;
    for (const auto &[a, b] : segments) {
        if (a == b) {
            ++counter;
        } else {
            counter += (b - a + 1) + comb(b - a + 1);
        }
    }
    return length + comb(length) - counter;
}

int main() {

    int n, m, pos;
    scanf("%d %d", &n, &m);
    vector<bool> A(n, false);
    while (m--) {
        scanf("%d", &pos);
        A.at(pos - 1) = true;
    }
    printf("%lld\n", solve(A));
    return 0;
}
