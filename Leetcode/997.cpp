class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        constexpr int MAXN = 1005;
        bitset<MAXN> t[MAXN];
        // add edges
        for (const auto &i : trust) {
            t[i[0]][i[1]] = true;
        }
        bool haveAns;
        for (int i = 1; i <= N; ++i) {
            if (t[i].none() && ) {
                haveAns = true;
                for (int j = 1; j <= N; ++j) {
                    if (j == i) {
                        continue;
                    }
                    if (!t[j][i]) {
                        haveAns = false;
                        break;
                    }
                }
                if (haveAns) {
                    return i;
                }
            }
        }
        return -1;
    }
};