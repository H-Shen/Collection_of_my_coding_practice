constexpr int MAXN = 26;

class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    unordered_map<int, unordered_set<int> > AL;
    vector<int> result;
    vector<int> vis;
    // toposort
    bool dfs(int u) {
        vis[u] = -1;
        for (const auto &v : AL[u]) {
            if (vis[v] < 0) {
                return false;
            }
            else if (vis[v] == 0) {
                if (!dfs(v)) {
                    return false;
                }
            }
        }
        vis[u] = 1;
        result.emplace_back(u);
        return true;
    }
    string alienOrder(vector<string>& words) {
        int n = (int)words.size();
        if (n == 1) {
            unordered_set<char> unset(words.front().begin(), words.front().end());
            return string(unset.begin(), unset.end());
        }
        else {
            string ans;
            for (const auto &i : words) {
                for (const auto &ch : i) {
                    AL[ch - 'a'];
                }
            }
            int length1, length2, minLength, u, v;
            bool hasRelationship;
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i+1; j < n; ++j) {
                    length1 = (int)words[i].size();
                    length2 = (int)words[j].size();
                    minLength = min(length1, length2);
                    hasRelationship = false;
                    for (int k = 0; k < minLength; ++k) {
                        if (words[i][k] != words[j][k]) {
                            u = words[i][k] - 'a';
                            v = words[j][k] - 'a';
                            AL[u].insert(v);
                            hasRelationship = true;
                            break;
                        }
                    }
                    if (!hasRelationship) {
                        if (length1 > length2) {
                            return ans;
                        }
                    }
                }
            }
            vis.resize(MAXN);
            for (const auto &[k, v] : AL) {
                if (vis[k] == 0) {
                    if (!dfs(k)) {
                        return ans; // no toposort
                    }
                }
            }
            reverse(result.begin(), result.end());
            for (const auto &i : result) {
                ans.push_back(i + 'a');
            }
            return ans;
        }
    }
};