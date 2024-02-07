class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> unset;
        for (int i = 1; i <= k; ++i) {
            unset.insert(i);
        }
        int cnt = 0;
        while (!unset.empty()) {
            unset.erase(nums.back());
            nums.pop_back();
            ++cnt;
        }
        return cnt;
    }
};