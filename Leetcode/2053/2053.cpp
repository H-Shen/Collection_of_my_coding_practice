class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,pair<int,int>> unmap;
        int n = (int)arr.size();
        for (int i = 0; i < n; ++i) {
            ++unmap[arr[i]].first;
            unmap[arr[i]].second = i;
        }
        vector<pair<string,int>> vec;
        for (auto &[k,v] : unmap) {
            if (v.first == 1) {
                vec.emplace_back(k, v.second);
            }
        }
        if ((int)vec.size() < k) {
            return string();
        }
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r) {
            return l.second < r.second; 
        });
        return vec[k-1].first;
    }
};