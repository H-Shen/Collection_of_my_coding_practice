constexpr int MAXN = 26;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<vector<int>> dist(MAXN);
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            dist[s[i] - 'a'].emplace_back(i);
        }
        for (int i = 0; i < MAXN; ++i) {
            if (!dist[i].empty()) {
                if (distance[i] != dist[i].back() - dist[i].front() - 1) {
                    return false;
                }
            }
        }
        return true;
    }
};