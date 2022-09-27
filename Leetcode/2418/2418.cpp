class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = (int)names.size();
        vector<pair<string, int>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i].first = names[i];
            vec[i].second = heights[i];
        }
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            return l.second > r.second;
        });
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = vec[i].first;
        }
        return ans;
    }
};