class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> out_deg;
        string u, v;
        for (const auto &i : paths) {
            u = i[0];
            v = i[1];
            out_deg[u] = true;
            if (out_deg.find(v) == out_deg.end()) {
                out_deg[v] = false;
            }
        }
        for (const auto &[k, v] : out_deg) {
            if (!v) {
                return k;
            }
        }
        return string();
    }
};