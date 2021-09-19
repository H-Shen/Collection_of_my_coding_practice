constexpr int EXIST = 0x3f3f3f3f;

class Solution {
public:
    int getVal(int n) {
        if (n >= 2*EXIST) {
            n -= 2*EXIST;
        }
        else if (n >= EXIST) {
            n -= EXIST;
        }
        return n;
    }
    vector<int> findDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            int val = getVal(nums[i]);
            nums[val-1] += EXIST;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 2*EXIST) {
                ans.emplace_back(i+1);
            }
        }
        return ans;
    }
};