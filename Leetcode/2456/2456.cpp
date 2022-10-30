using ll = long long;

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, ll> creator2views;
        unordered_map<string, vector<pair<string,int>>> creator2ids;
        int n = (int)creators.size();
        for (int i = 0; i < n; ++i) {
            creator2views[creators[i]] += views[i];
            creator2ids[creators[i]].emplace_back(ids[i], views[i]);
        }
        vector<vector<string>> ans;
        ll maxView = 0;
        for (auto&[k,v] : creator2views) {
            maxView = max(maxView, v);
        }
        auto cmp = [](const auto &l, const auto &r){
                    if (l.second == r.second) {
                        return l.first < r.first;
                    }
                    return l.second > r.second;
                };
        for (auto&[k,v] : creator2views) {
            if (v == maxView) {
                ans.emplace_back(vector<string>{k, min_element(creator2ids[k].begin(),creator2ids[k].end(),cmp)->first});
            }
        }
        return ans;
    }
};