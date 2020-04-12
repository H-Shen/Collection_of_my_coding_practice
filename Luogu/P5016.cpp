#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
vector<ll> A;

int main() {

    ll n;
    scanf("%lld", &n);
    A.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &A.at(i));
    }
    ll m, p_1, s_1, s_2;
    scanf("%lld %lld %lld %lld", &m, &p_1, &s_1, &s_2);
    A.at(p_1) += s_1;
    ll dragon = 0;
    for (ll i = 1; i < m; ++i) {
        dragon += A.at(i) * (m - i);
    }
    ll tiger = 0;
    for (ll i = m + 1; i <= n; ++i) {
        tiger += A.at(i) * (i - m);
    }
    // Linear check
    ll min_dist = numeric_limits<ll>::max();
    ll new_dragon, new_tiger;
    for (ll p_2 = 1; p_2 <= n; ++p_2) {
        if (p_2 == m) {
            min_dist = min(min_dist, abs(dragon - tiger));
        } else if (p_2 < m) {
            new_dragon = dragon + (m - p_2) * s_2;
            new_tiger = tiger;
            min_dist = min(min_dist, abs(new_dragon - new_tiger));
        } else if (p_2 > m) {
            new_dragon = dragon;
            new_tiger = tiger + (p_2 - m) * s_2;
            min_dist = min(min_dist, abs(new_dragon - new_tiger));
        }
    }
    ll current_min_dist = numeric_limits<ll>::max();
    for (ll p_2 = 1; p_2 <= n; ++p_2) {
        if (p_2 == m) {
            current_min_dist = min(current_min_dist, abs(dragon - tiger));
        } else if (p_2 < m) {
            new_dragon = dragon + (m - p_2) * s_2;
            new_tiger = tiger;
            current_min_dist = min(current_min_dist, abs(new_dragon - new_tiger));
        } else if (p_2 > m) {
            new_dragon = dragon;
            new_tiger = tiger + (p_2 - m) * s_2;
            current_min_dist = min(current_min_dist, abs(new_dragon - new_tiger));
        }
        if (current_min_dist == min_dist) {
            printf("%lld\n", p_2);
            break;
        }
    }

    return 0;
}