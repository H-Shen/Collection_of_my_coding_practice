class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int> unmap;
        for (const auto &i : nums) {
            ++unmap[i];
        }
        if (unmap.size() == 1) return 0;
        vector<pair<int,int>> v(unmap.size());
        auto iter = v.begin();
        for (const auto &[i,j] : unmap) {
            iter->first = i;
            iter->second = j;
            ++iter;
        }
        sort(v.begin(),v.end(),[](const pair<int,int> &l, const pair<int,int> &r){
            return l.first > r.first;
        });
        int counter = 0;
        int n = (int)v.size();
        for (int i = 1; i < n; ++i) {
            counter += v[i-1].second;
            v[i].second += v[i-1].second;
        }
        return counter;
    }
};