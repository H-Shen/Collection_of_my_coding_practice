class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        multiset<int> ms(nums.begin(),nums.end());
        unordered_set<int> unset;
        while (!ms.empty()) {
            int minVal = *ms.begin();
            ms.erase(ms.begin());
            int maxVal = *(--ms.end());
            ms.erase(--ms.end());
            unset.insert(minVal + maxVal);
        }
        return (int)unset.size();
    }
};