#include <cstdio>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;

int main() {
    unordered_map<int, vector<int> > A;
    int n, teamId, memberId, grade;
    scanf("%d", &n);
    while (n--) {
        scanf("%d-%d %d", &teamId, &memberId, &grade);
        A[teamId].push_back(grade);
    }

    int maxScore = INT_MIN;
    int teamIdWithMaxScore = -1;
    int tmpSum = -1;

    for (auto it = A.begin(); it != A.end(); ++it) {
        tmpSum = accumulate(it->second.begin(), it->second.end(), 0);
        if (tmpSum > maxScore) {
            maxScore = tmpSum;
            teamIdWithMaxScore = it->first;
        }
    }

    printf("%d %d\n", teamIdWithMaxScore, maxScore);
    return 0;
}