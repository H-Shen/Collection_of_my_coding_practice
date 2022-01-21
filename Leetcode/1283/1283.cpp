class Solution {
public:
    bool check(vector<int>& nums, int threshold, int d) {
        int sum = 0;
        for (auto& i : nums) {
            sum += i / d;
            if (i % d != 0) ++sum;
            if (sum > threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = (int)nums.size();
        int l = 1;
        int r = *max_element(nums.begin(),nums.end())+1;
        int mid;
        int ans = numeric_limits<int>::max();
        while (l <= r) {
            mid = l + ((r-l) >> 1);
            if (check(nums, threshold, mid)) {
                ans = min(ans,mid);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};