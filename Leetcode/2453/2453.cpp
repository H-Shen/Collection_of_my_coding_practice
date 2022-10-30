class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,vector<int>> unmap;
        for (auto&i : nums) {
            unmap[i % space].emplace_back(i);
        }
        size_t maxFreq = 0;
        for (auto&[k,v] : unmap) {
            maxFreq = max(maxFreq, v.size());
        }
        int minVal = numeric_limits<int>::max();
        for (auto&[k,v] : unmap) {
            if (v.size() == maxFreq) {
                minVal = min(minVal, *min_element(v.begin(),v.end()));
            }
        }
        return minVal;
    }
};