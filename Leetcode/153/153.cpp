constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) {
            return nums[0];
        }
        int left_val = nums[0];
        int right_val = nums[n-1];
        if (left_val < right_val) {
            return left_val;
        }
        int ans = INF;
        int l = 0;
        int r = n-1;
        int mid;
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (nums[mid] >= left_val) {
                l = mid + 1;
            }
            else {
                ans = min(ans, mid);
                r = mid - 1;
            }
        }
        return min(*min_element(nums.begin(),nums.begin()+ans), *min_element(nums.begin()+ans,nums.end()));
    }
};