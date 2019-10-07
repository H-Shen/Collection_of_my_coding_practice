// https://open.kattis.com/problems/vote
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    int candidates;
    int totalVotes;
    int maxVotes;
    int freqOfMaxVotes;
    scanf("%d", &n);
    while (n--) {
        totalVotes = 0;
        scanf("%d", &candidates);
        vector<int> A(candidates);
        for (auto &i : A) {
            scanf("%d", &i);
            totalVotes += i;
        }
        maxVotes = -1;
        for (const auto &i : A) {
            maxVotes = max(maxVotes, i);
        }
        freqOfMaxVotes = 0;
        for (const auto &i : A) {
            if (i == maxVotes) {
                ++freqOfMaxVotes;
            }
        }
        if (freqOfMaxVotes != 1) {
            printf("no winner\n");
        } else {
            if (maxVotes > totalVotes / 2) {
                printf("majority winner ");
            } else {
                printf("minority winner ");
            }
            printf("%d\n", static_cast<int>(find(A.begin(), A.end(), maxVotes) - A.begin() + 1));
        }
    }

    return 0;
}
