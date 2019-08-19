#include <bits/stdc++.h>

using namespace std;

struct issue {
    int score;
    unordered_set<char> ans;
};

int main() {
    int n, m, i, j, tmp0, tmp1;
    char tmpChar;
    scanf("%d %d", &n, &m);
    vector<vector<int> > errorCnt(m);
    vector<issue> Ans(m);
    vector<double> studentScore(n);

    for (i = 0; i < m; ++i) {

        scanf("%d %d %d", &Ans[i].score, &tmp0, &tmp1);
        errorCnt[i].resize(static_cast<size_t>(tmp0));
        getchar();

        for (j = 0; j < tmp1; ++j) {
            scanf("%c", &tmpChar);
            getchar();
            Ans[i].ans.insert(tmpChar);
        }
    }


    bool out = true;
    bool rightAns = true;
    bool noOneWrong = true;
    int issueCnt = 0;
    string s;

    for (i = 0; i < n; ++i) {

        getline(cin, s);
        tmp0 = static_cast<int>(s.size());
        out = true;
        unordered_set<char> tmpAns;
        issueCnt = 0;

        for (j = 0; j < tmp0; ++j) {

            if (out && s[j] == '(') {

                out = false;

            } else if (!out && s[j] == ')') {

                out = true;

                for (const auto &p : tmpAns) {
                    if (Ans[issueCnt].ans.find(p) == Ans[issueCnt].ans.end()) {
                        rightAns = false;
                        noOneWrong = false;
                        ++errorCnt[issueCnt][p - 'a'];
                    }
                }

                for (const auto &p : Ans[issueCnt].ans) {
                    if (tmpAns.find(p) == tmpAns.end()) {
                        ++errorCnt[issueCnt][p - 'a'];
                    }
                }

                if (rightAns && tmpAns.size() < Ans[issueCnt].ans.size() && !tmpAns.empty()) {

                    studentScore[i] = studentScore[i] + (double) Ans[issueCnt].score / 2.0;
                } else if (rightAns && tmpAns.size() == Ans[issueCnt].ans.size()) {
                    studentScore[i] += (double) Ans[issueCnt].score;
                }

                tmpAns.clear();
                ++issueCnt;
                rightAns = true;

            } else if (!out && islower(s[j])) {
                tmpAns.insert(s[j]);
            }
        }
    }

    for (const auto &p : studentScore) {
        printf("%.1lf\n", p);
    }

    if (noOneWrong) {
        printf("Too simple\n");
    } else {
        int maxEF = -1;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < (int) errorCnt[i].size(); ++j) {
                maxEF = max(maxEF, errorCnt[i][j]);
            }
        }

        for (i = 0; i < m; ++i) {
            for (j = 0; j < (int) errorCnt[i].size(); ++j) {
                if (errorCnt[i][j] == maxEF) {
                    printf("%d %d-%c\n", maxEF, i + 1, j + 'a');
                }
            }
        }
    }
    return 0;
}