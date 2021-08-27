class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        constexpr int MAXN = 405;
        bitset<MAXN> exist[MAXN];
        int degree[MAXN]{};
        for (auto &i : edges) {
            if (i.front() > i.back()) swap(i.front(), i.back());
            exist[i.front()][i.back()] = true;
            ++degree[i.front()];
            ++degree[i.back()];
        }
        int m = (int)edges.size();
        int answer = -1;
        for (int i = 1; i <= n - 2; ++i) {
            for (int j = i + 1; j <= n - 1; ++j) {
                for (int k = j + 1; k <= n; ++k) {
                    if (exist[i][j] && exist[j][k] && exist[i][k]) {
                        if (answer == -1) {
                            answer = degree[i] + degree[j] + degree[k] - 6;
                        } else {
                            answer = min(answer, degree[i] + degree[j] + degree[k] - 6);
                        }
                    }
                }
            }
        }
        return answer;
    }
};