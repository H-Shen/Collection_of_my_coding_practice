// https://ac.nowcoder.com/acm/problem/18951

#include <bits/stdc++.h>

using namespace std;

struct hashFunctionForPair {
    auto operator() (const pair<int, int> &p) const {
        auto hash1 = hash<int>{}(p.first);
        auto hash2 = hash<int>{}(p.second);
        return hash1 ^ hash2;
    };
};

int main() {

    int n;
    scanf("%d\n", &n);
    vector<int> xList(n);
    vector<int> yList(n);
    for (int i = 0; i != n; ++i) {
        scanf("%d", &xList[i]);
    }
    for (int i = 0; i != n; ++i) {
        scanf("%d", &yList[i]);
    }
    unordered_map<int, int> positiveSlope;
    unordered_map<int, int> negativeSlope;
    unordered_map<pair<int, int>, int, hashFunctionForPair> yInterceptPairToPointCount;
    for (int i = 0; i < n; ++i) {
        ++positiveSlope[yList[i] - xList[i]];
        ++negativeSlope[yList[i] + xList[i]];
        ++yInterceptPairToPointCount[{yList[i] - xList[i], yList[i] + xList[i]}];
    }
    int maxCount = -1;
    for (const auto &i : positiveSlope) {
        maxCount = max(maxCount, i.second);
    }
    vector<int> positiveSlopeWithMaxCount;
    for (const auto &i : positiveSlope) {
        if (i.second == maxCount) {
            positiveSlopeWithMaxCount.emplace_back(i.first);
        }
    }
    maxCount = -1;
    for (const auto &i : negativeSlope) {
        maxCount = max(maxCount, i.second);
    }
    vector<int> negativeSlopeWithMaxCount;
    for (const auto &i : negativeSlope) {
        if (i.second == maxCount) {
            negativeSlopeWithMaxCount.emplace_back(i.first);
        }
    }

    // We select one element from positiveSlopeWithMaxCount as c0 and one element from negativeSlopeWithMaxCount as c1
    // thus two lines are y = x + c0 and y = -x + c1. Then we count the maximal points crossed by such (c0, c1).
    maxCount = -1;
    for (const int &c0 : positiveSlopeWithMaxCount) {
        for (const int &c1 : negativeSlopeWithMaxCount) {
            if (yInterceptPairToPointCount.find({c0, c1}) != yInterceptPairToPointCount.end()) {
                maxCount = max(maxCount, positiveSlope[c0] + negativeSlope[c1] - yInterceptPairToPointCount[{c0, c1}]);
            } else {
                maxCount = max(maxCount, positiveSlope[c0] + negativeSlope[c1]);
            }
        }
    }
    printf("%d\n", maxCount);

    return 0;
}