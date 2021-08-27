class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string,int> node2id;
        int id = 0;
        for (const auto &i : favoriteCompanies) {
            for (const auto &j : i) {
                if (node2id.find(j) == node2id.end()) {
                    node2id[j] = id;
                    ++id;
                }
            }
        }
        int n = (int)favoriteCompanies.size();
        vector<vector<int> > v(n);
        for (int i = 0; i < n; ++i) {
            int m = (int)favoriteCompanies[i].size();
            v[i].resize(m);
            for (int j = 0; j < m; ++j) {
                v[i][j] = node2id[favoriteCompanies[i][j]];
            }
            sort(v[i].begin(), v[i].end());
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            bool haveAns = true;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (includes(v[j].begin(),v[j].end(),v[i].begin(),v[i].end())) {
                        haveAns = false;
                        break;
                    }
                }
            }
            if (haveAns) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};