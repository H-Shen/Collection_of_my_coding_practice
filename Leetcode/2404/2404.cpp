class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (auto&i : nums) {
            if (!(i & 1)) {
                ++freq[i];
            }
        }
        if (freq.empty()) {
            return -1;
        }
        vector<pair<int,int>> vec(freq.begin(),freq.end());
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            if (l.second == r.second) {
                return l.first < r.first;
            }
            return l.second > r.second;
        });
        return vec.front().first;
    }
};