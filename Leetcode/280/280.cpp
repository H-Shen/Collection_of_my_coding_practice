class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() <= 2) {
            return;
        }
        int n = (int)nums.size();
        for (int i = 1; i + 1 < n; i += 2) {
            swap(nums[i],nums[i+1]);
        }
    }
};