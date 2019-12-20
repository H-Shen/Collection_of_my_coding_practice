#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, vector<int> > A;
    int n, teamId, memberId, grade;
    scanf("%d", &n);
    while (n--) {
        scanf("%d-%d %d", &teamId, &memberId, &grade);
        A[teamId].push_back(grade);
    }

    int maxScore = numeric_limits<int>::min();
    int teamIdWithMaxScore = -1;
    int tmpSum;

    for (const auto & it : A) {
        tmpSum = accumulate(it.second.begin(), it.second.end(), 0);
        if (tmpSum > maxScore) {
            maxScore = tmpSum;
            teamIdWithMaxScore = it.first;
        }
    }

    printf("%d %d\n", teamIdWithMaxScore, maxScore);
    return 0;
}