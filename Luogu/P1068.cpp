#include <bits/extc++.h>

using namespace std;

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int> > A(n);
    for (auto &i : A) {
        scanf("%d %d", &i.first, &i.second);
    }

    int lowerBoundRank = static_cast<int>(m * 1.5);
    sort(A.begin(), A.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs){
       return (lhs.second > rhs.second);
    });
    int lowerBound = A.at(lowerBoundRank - 1).second;

    decltype(A) output;
    for (const auto &i : A) {
        if (i.second >= lowerBound) {
            output.emplace_back(i);
        }
    }
    sort(output.begin(), output.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs){
        if (lhs.second == rhs.second) {
            return (lhs.first < rhs.first);
        }
        return (lhs.second > rhs.second);
    });
    printf("%d %zu\n", lowerBound, output.size());
    for (const auto &[id, score] : output) {
        printf("%d %d\n", id, score);
    }

    return 0;
}
