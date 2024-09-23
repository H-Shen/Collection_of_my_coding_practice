#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int id, score, n;
    cin >> n;
    unordered_map<int, int> A;
    while (n--) {
        cin >> id >> score;
        A[id] += score;
    }

    int maxScore = numeric_limits<int>::min();
    int maxScoreId = 0;

    for (const auto it : A) {
        if (it.second > maxScore) {
            maxScore = it.second;
            maxScoreId = it.first;
        }
    }

    cout << maxScoreId << ' ' << maxScore << endl;

    return 0;
}