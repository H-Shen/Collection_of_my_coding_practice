class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        constexpr int EXIST = 0x3f3f3f3f;
        int n = (int)nums.size();
        int key;
        for (int i = 0; i < n; ++i) {
            key = nums[i];
            // restore
            if (key > EXIST) {
                key -= EXIST;
            }
            // the key already exists
            if (nums[key-1] > EXIST) {
                continue;
            }
            nums[key-1] += EXIST;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= EXIST) {
                ans.emplace_back(i+1);
            }
        }
        return ans;
    }
};