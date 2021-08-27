class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, int> node2id;
        vector<string> id2node;
        int id = 0;
        for (const auto &i : regions) {
            for (const auto &j : i) {
                if (node2id.find(j) == node2id.end()) {
                    node2id[j] = id;
                    ++id;
                    id2node.emplace_back(j);
                }
            }
        }
        if (node2id.find(region1) == node2id.end()) {
            node2id[region1] = id;
            ++id;
            id2node.emplace_back(region1);
        }
        if (node2id.find(region2) == node2id.end()) {
            node2id[region2] = id;
            ++id;
            id2node.emplace_back(region2);
        }
        vector<int> father(id, -1);
        int u, v;
        for (const auto &i : regions) {
            int length = (int)i.size();
            u = node2id[i[0]];
            for (int j = 1; j < length; ++j) {
                v = node2id[i[j]];
                father[v] = u;
            }
        }
        // lca
        u = node2id[region1];
        unordered_set<int> unset;
        while (u != -1) {
            unset.insert(u);
            u = father[u];
        }
        u = node2id[region2];
        while (u != -1) {
            if (unset.find(u) != unset.end()) {
                break;
            }
            u = father[u];
        }
        return id2node[u];
    }
};