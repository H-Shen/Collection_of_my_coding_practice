#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <climits>

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

    int maxScore = INT_MIN;
    int maxScoreId = 0;

    for (auto it = A.cbegin(); it != A.cend(); ++it) {
        if (it->second > maxScore) {
            maxScore = it->second;
            maxScoreId = it->first;
        }
    }

    cout << maxScoreId << ' ' << maxScore << endl;

    return 0;
}