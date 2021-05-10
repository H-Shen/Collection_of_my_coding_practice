constexpr int MAXN = 26;

vector<vector<int> > AL;
vector<int> inDegree;
int n;

namespace Toposort {
    vector<int> result;
    vector<int> inDegreeCopy;
    bool kahn() {
        vector<int>().swap(result);
        inDegreeCopy = inDegree;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegreeCopy.at(i) == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.emplace_back(u);
            for (const auto &adj_v : AL[u]) {
                --inDegreeCopy.at(adj_v);
                if (inDegreeCopy.at(adj_v) == 0) {
                    q.push(adj_v);
                }
            }
        }
        return ((int)result.size() == n);
    }
}

class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    int counter = 0;
    string str;
    vector<vector<int> > dp;    // dp[i][j] 以i为起始点时颜色j最多的数量
    int solve(int u, char color) {
        // Base case 1:
        if (dp[u][color - 'a'] != -1) {
            return dp[u][color - 'a'];
        }
        // Base case 2:
        if (AL[u].empty()) {
            if (str[u] == color) {
                dp[u][color - 'a'] = 1;   
            } else {
                dp[u][color - 'a'] = 0;
            }
            return dp[u][color - 'a'];
        }
        if (str[u] == color) {
            for (const auto &v : AL[u]) {
                dp[u][color- 'a'] = max(dp[u][color- 'a'],1+solve(v,color));
            }
        }
        else {
            for (const auto &v : AL[u]) {
                dp[u][color- 'a'] = max(dp[u][color- 'a'], solve(v,color));
            }
        }
        return dp[u][color - 'a'];
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        decltype(AL)().swap(AL);
        decltype(inDegree)().swap(inDegree);
        decltype(dp)().swap(dp);
        set<char> uniqueColors(colors.begin(), colors.end());
        counter = 0;
        n = (int)colors.size();
        str = colors;
        inDegree.resize(n);
        dp.resize(n, vector<int>(MAXN, -1));
        for (const auto &i : edges) {
            ++inDegree[i[1]];
        }
        AL.resize(n);
        for (const auto &i : edges) {
            AL[i[0]].emplace_back(i[1]);
        }
        if (!Toposort::kahn()) {
            return -1;
        }
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                for (const auto &color : uniqueColors) {
                    counter = max(counter,solve(i, color));
                }
            }
        }
        return counter;
    }
};