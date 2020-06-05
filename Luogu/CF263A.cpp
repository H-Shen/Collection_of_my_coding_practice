#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 5;

int main() {

    vector<vector<int> > A(MAXN, vector<int>(MAXN));
    vector<pair<int, int> > temp;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            scanf("%d", &A.at(i).at(j));
            if (A.at(i).at(j) == 1) {
                temp.emplace_back(make_pair(i, j));
            }
        }
    }
    int dist = numeric_limits<int>::max();
    for (const auto &[i, j] : temp) {
        dist = min(dist, abs(i - 2) + abs(j - 2));  // Manhattan Distance
    }
    printf("%d\n", dist);

    return 0;
}

