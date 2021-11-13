class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // offline query
        // assign ID to each query
        int q = (int)queries.size();
        vector<int> id(q);
        iota(id.begin(),id.end(),0);
        // sort id
        sort(id.begin(),id.end(),[&](const auto &l, const auto &r){
            return queries[l] < queries[r];
        });
        vector<int> ans(q);
        set<int, greater<int>> s;
        sort(items.begin(),items.end(),[](const auto &l, const auto &r){
            return l[0] < r[0];
        });
        int n = (int)items.size();
        for (int i = 0, j = 0; i < q; ++i) {
            while (j < n) {
                if (items[j][0] <= queries[id[i]]) {
                    s.insert(items[j][1]);
                    ++j;
                } else {
                    break;
                }
            }
            // write to the mapping index
            if (s.empty()) {
                ans[id[i]] = 0;
            } else {
                ans[id[i]] = *s.begin();
            }
        }
        return ans;
    }
};