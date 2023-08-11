class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        auto check = [&](int i, int j) {
            if (j-i+1 <= 1) return false;
            bool flag = true;
            for (int pos = i; pos <= j-1; ++pos) {
                if (flag) {
                    if (nums[pos+1]-nums[pos] != 1) return false;
                }
                else {
                    if (nums[pos+1]-nums[pos] != -1) return false;
                }
                flag = !flag;
            }
            return true;
        };
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j >= i; --j) {
                if (j-i+1 < ans) break;
                if (check(i,j)) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};