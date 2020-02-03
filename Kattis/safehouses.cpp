// https://open.kattis.com/problems/safehouses
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

auto manhattan_dist = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
};

int main() {

    int n;
    scanf("%d", &n);
    vector<vector<char> > A(n, vector<char>(n));
    getchar();
    vector<pair<int, int> > spies;
    vector<pair<int, int> > safe_houses;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%c", &A.at(i).at(j));
            if (A.at(i).at(j) == 'S') {
                spies.emplace_back(i, j);
            } else if (A.at(i).at(j) == 'H') {
                safe_houses.emplace_back(i, j);
            }
        }
        getchar();
    }
    int min_distance_for_a_spy;
    int max_distance_for_all_spies = numeric_limits<int>::min();
    for (const auto &i : spies) {
        min_distance_for_a_spy = numeric_limits<int>::max();
        for (const auto &j : safe_houses) {
            min_distance_for_a_spy = min(min_distance_for_a_spy, manhattan_dist(i, j));
        }
        max_distance_for_all_spies = max(max_distance_for_all_spies, min_distance_for_a_spy);
    }
    printf("%d\n", max_distance_for_all_spies);
    return 0;
}
