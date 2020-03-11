#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 25;
vector<vector<ll> > dp(MAXN, vector<ll>(MAXN));
vector<vector<bool> > horse_locations(MAXN, vector<bool>(MAXN));

int main() {

    int dest_i, dest_j, horse_i, horse_j;
    scanf("%d %d %d %d", &dest_i, &dest_j, &horse_i, &horse_j);
    ++dest_i;
    ++dest_j;
    ++horse_i;
    ++horse_j;

    horse_locations.at(horse_i).at(horse_j) = true;
    try { horse_locations.at(horse_i + 2).at(horse_j + 1) = true; } catch (...) {}
    try { horse_locations.at(horse_i + 2).at(horse_j - 1) = true; } catch (...) {}
    try { horse_locations.at(horse_i + 1).at(horse_j - 2) = true; } catch (...) {}
    try { horse_locations.at(horse_i + 1).at(horse_j + 2) = true; } catch (...) {}
    try { horse_locations.at(horse_i - 1).at(horse_j + 2) = true; } catch (...) {}
    try { horse_locations.at(horse_i - 1).at(horse_j - 2) = true; } catch (...) {}
    try { horse_locations.at(horse_i - 2).at(horse_j + 1) = true; } catch (...) {}
    try { horse_locations.at(horse_i - 2).at(horse_j - 1) = true; } catch (...) {}

    dp.at(1).at(0) = 1;
    for(int i = 1; i <= MAXN - 1;i++) {
        for(int j = 1; j <= MAXN - 1; j++) {
            if (!horse_locations.at(i).at(j)) {
                dp.at(i).at(j) = dp.at(i).at(j - 1) + dp.at(i - 1).at(j);
            }
        }
    }
    printf("%lld\n", dp.at(dest_i).at(dest_j));
    return 0;
}
