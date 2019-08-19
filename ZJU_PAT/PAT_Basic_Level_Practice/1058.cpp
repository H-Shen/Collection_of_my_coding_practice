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
    vector<int> errorCnt(static_cast<size_t>(m));
    vector<issue> Ans(static_cast<size_t>(m));
    vector<int> studentScore(static_cast<size_t>(n));

    for (i = 0; i < m; ++i) {

        scanf("%d %d %d", &Ans[i].score, &tmp0, &tmp1);
        getchar();

        for (j = 0; j < tmp1; ++j) {
            scanf("%c", &tmpChar);
            getchar();
            Ans[i].ans.insert(tmpChar);
        }
    }


    bool out;
    bool rightAns = true;
    bool noOneWrong = true;
    int issueCnt = 0;
    string s;

    for (i = 0; i < n; ++i) {

        getline(cin, s);
        tmp0 = static_cast<int>(s.size());
        out = true;
        vector<char> tmpAns;
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
                    }
                }

                if (tmpAns.size() != Ans[issueCnt].ans.size()) {
                    rightAns = false;
                }
                if (rightAns) {
                    studentScore[i] += Ans[issueCnt].score;
                } else {
                    ++errorCnt[issueCnt];
                }

                vector<char>().swap(tmpAns);
                ++issueCnt;
                rightAns = true;

            } else if (!out && islower(s[j])) {
                tmpAns.push_back(s[j]);
            }
        }
    }

    for (const auto &p : studentScore) {
        printf("%d\n", p);
    }


    if (noOneWrong) {
        printf("Too simple\n");
    } else {
        pair<int, vector<int> > res;
        int maxErrorFreq = *max_element(errorCnt.begin(), errorCnt.end());
        res.first = maxErrorFreq;
        for (i = 0; i < m; ++i) {
            if (errorCnt[i] == maxErrorFreq) {
                res.second.push_back(i + 1);
            }
        }
        printf("%d ", maxErrorFreq);
        for (i = 0; i < (int) res.second.size() - 1; ++i) {
            printf("%d ", res.second[i]);
        }
        printf("%d\n", res.second[res.second.size() - 1]);
    }

    return 0;
}
