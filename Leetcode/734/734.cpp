class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        int id = 0;
        unordered_map<string, int> unmap;
        for (const auto &i : sentence1) {
            if (unmap.find(i) == unmap.end()) {
                unmap[i] = id;
                ++id;
            }
        }
        for (const auto &i : sentence2) {
            if (unmap.find(i) == unmap.end()) {
                unmap[i] = id;
                ++id;
            }
        }
        for (const auto &i : similarPairs) {
            for (const auto &j : i) {
                if (unmap.find(j) == unmap.end()) {
                    unmap[j] = id;
                    ++id;
                }
            }
        }
        struct myHashFunc {
            size_t operator()(const pair<int,int> &o) const {
                return hash<int>()(o.first)^hash<int>()(o.second);
            }
        };
        unordered_set<pair<int,int>, myHashFunc> edges;
        int u, v;
        for (const auto &i : similarPairs) {
            u = unmap[i[0]];
            v = unmap[i[1]];
            if (u > v) swap(u, v);
            edges.insert({u,v});
        }
        int n = (int)sentence1.size();
        for (int i = 0; i < n; ++i) {
            u = unmap[sentence1[i]];
            v = unmap[sentence2[i]];
            if (u == v) continue;
            if (u > v) swap(u, v);
            if (edges.find({u,v}) == edges.end()) {
                return false;
            }
        }
        return true;
    }
};