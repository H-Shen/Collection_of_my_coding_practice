#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10, convert = 32;
char s_id[MAXN], s_school[MAXN];


struct schoolUnit {
    string school;
    int studentNumber = 0;
    int B_score_sum = 0;
    int A_score_sum = 0;
    int T_score_sum = 0;
    int weighting_sum = 0;
    int rank = 0;
};

bool cmp(const schoolUnit &a, const schoolUnit &b) {
    if (a.weighting_sum == b.weighting_sum) {
        if (a.studentNumber == b.studentNumber) {
            return (a.school < b.school);
        }
        return (a.studentNumber < b.studentNumber);
    }
    return (a.weighting_sum > b.weighting_sum);
}


int main() {
    int n, i, score;
    scanf("%d", &n);

    unordered_map<string, schoolUnit> A;
    string str_school;

    for (i = 0; i < n; ++i) {
        scanf("%s %d %s", s_id, &score, s_school);
        str_school = s_school;
        for (auto &ch : str_school) {
            if (isupper(ch)) {
                ch = static_cast<char>(ch + convert);
            }
        }
        A[str_school].school = str_school;
        ++A[str_school].studentNumber;
        if (s_id[0] == 'A') {
            A[str_school].A_score_sum += score;
        } else if (s_id[0] == 'B') {
            A[str_school].B_score_sum += score;
        } else {
            A[str_school].T_score_sum += score;
        }
    }

    vector<schoolUnit> rankList(A.size());
    i = 0;
    for (const auto &it : A) {
        rankList[i] = it.second;
        rankList[i].weighting_sum = static_cast<int>(static_cast<double>(rankList[i].B_score_sum) / 1.5 +
                                                     static_cast<double>(rankList[i].A_score_sum) +
                                                     static_cast<double>(rankList[i].T_score_sum) * 1.5);
        ++i;
    }
    sort(rankList.begin(), rankList.end(), cmp);

    int currentRank = 1;
    int len = static_cast<int>(rankList.size());
    rankList[0].rank = 1;
    for (i = 1; i < len; ++i) {
        ++currentRank;
        if (rankList[i].weighting_sum == rankList[i - 1].weighting_sum) {
            rankList[i].rank = rankList[i - 1].rank;
        } else {
            rankList[i].rank = currentRank;
        }
    }

    printf("%d\n", len);
    for (i = 0; i < len; ++i) {
        printf("%d %s %d %d\n", rankList[i].rank, rankList[i].school.c_str(), rankList[i].weighting_sum,
               rankList[i].studentNumber);
    }
    return 0;
}