class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> pos;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                pos.emplace_back(i);
            }
        }
        if (pos.size() <= 1) return true;
        n = (int)pos.size();
        for (int i = 0; i < n - 1; ++i) {
            if (pos[i + 1] - pos[i] - 1 < k) return false;
        }
        return true;
    }
};